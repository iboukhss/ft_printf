/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:54:52 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/12 21:01:46 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tap.h"
#include "ft_printf.h"

#include <string.h>
#include <fcntl.h>
#include <limits.h>

// test structure
struct {
	char buf1[80];
	char buf2[80];
	int len1;
	int len2;
} t;

#define PRINT(format, ...)								\
do {													\
	memset(&t, 0, sizeof(t));							\
	t.len1 = ft_printf(format, ##__VA_ARGS__);			\
	read(pipefd[0], t.buf1, sizeof(t.buf1));			\
	t.len2 = sprintf(t.buf2, format, ##__VA_ARGS__);	\
	cmp_ok(t.len1, "==", t.len2);						\
	cmp_mem(t.buf1, t.buf2, t.len2);					\
} while (0)

int	main(void)
{
	plan(NO_PLAN);

	// redirect stdout
	int pipefd[2];
	pipe(pipefd);
	fcntl(pipefd[0], F_SETFL, O_NONBLOCK);
	int saved = dup(STDOUT_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);

	diag("signed int #############################");
	PRINT("%-10.5d", 42);
	PRINT("%-10.5d", -42);
	PRINT("%-10.5d", 0);
	PRINT("%-20.15d", INT_MIN);
	PRINT("%-20.15d", INT_MAX);

	PRINT("%-.1d", 42);
	PRINT("%-.1d", -42);
	PRINT("%-.1d", 0);
	PRINT("%-.1d", INT_MIN);
	PRINT("%-.1d", INT_MAX);

	PRINT("%-.0d", 42);
	PRINT("%-.0d", -42);
	PRINT("%-.0d", 0);
	PRINT("%-.0d", INT_MIN);
	PRINT("%-.0d", INT_MAX);

	diag("unsigned int ###########################");
	PRINT("%-10.5u", 42);
	PRINT("%-10.5u", -42);
	PRINT("%-10.5u", 0);
	PRINT("%-20.15u", UINT_MAX);

	PRINT("%-.1u", 42);
	PRINT("%-.1u", -42);
	PRINT("%-.1u", 0);
	PRINT("%-.1u", UINT_MAX);

	PRINT("%-.0u", 42);
	PRINT("%-.0u", -42);
	PRINT("%-.0u", 0);
	PRINT("%-.0u", UINT_MAX);

	diag("hexadecimal ############################");
	PRINT("%-10.5x", 42);
	PRINT("%-10.5x", -42);
	PRINT("%-10.5x", 0);
	PRINT("%-20.15u", UINT_MAX);

	PRINT("%-.1x", 42);
	PRINT("%-.1x", -42);
	PRINT("%-.1x", 0);
	PRINT("%-.1x", UINT_MAX);

	PRINT("%-.0x", 42);
	PRINT("%-.0x", -42);
	PRINT("%-.0x", 0);
	PRINT("%-.0x", UINT_MAX);

	diag("string #################################");
	PRINT("%-s", "hello!");
	PRINT("%-s", (char *)NULL);

	PRINT("%-.0s", "hello!");
	PRINT("%-.0s", (char *)NULL);

	PRINT("%-10.5s", "hello!");
	PRINT("%-10.5s", (char *)NULL);

	PRINT("%-10.0s", "hello!");
	PRINT("%-10.0s", (char *)NULL);

	// teardown
	dup2(saved, 1);
	close(pipefd[0]);
	close(pipefd[1]);

	done_testing();
}
