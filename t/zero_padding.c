/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:22:26 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/11 20:21:18 by iboukhss         ###   ########.fr       */
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
	PRINT("%05d", 42);
	PRINT("%05d", -42);
	PRINT("%05d", 0);
	PRINT("%015d", INT_MIN);
	PRINT("%015d", INT_MAX);

	PRINT("%01d", 42);
	PRINT("%01d", -42);
	PRINT("%01d", 0);
	PRINT("%01d", INT_MIN);
	PRINT("%01d", INT_MAX);

	PRINT("%05.0d", 42);
	PRINT("%05.0d", -42);
	PRINT("%05.0d", 0);
	PRINT("%015.0d", INT_MIN);
	PRINT("%015.0d", INT_MAX);

	diag("unsigned int ###########################");
	PRINT("%05u", 42);
	PRINT("%05u", -42);
	PRINT("%05u", 0);
	PRINT("%015u", UINT_MAX);

	PRINT("%01u", 42);
	PRINT("%01u", -42);
	PRINT("%01u", 0);
	PRINT("%01u", UINT_MAX);

	PRINT("%05.0u", 42);
	PRINT("%05.0u", -42);
	PRINT("%05.0u", 0);
	PRINT("%015.0u", UINT_MAX);

	diag("hexadecimal ############################");
	PRINT("%05x", 42);
	PRINT("%015x", -42);
	PRINT("%05x", 0);
	PRINT("%015x", UINT_MAX);

	PRINT("%#05x", 42);
	PRINT("%#015x", -42);
	PRINT("%#05x", 0);
	PRINT("%#015x", UINT_MAX);

	PRINT("%01x", 42);
	PRINT("%01x", -42);
	PRINT("%01x", 0);
	PRINT("%01x", UINT_MAX);

	PRINT("%#01x", 42);
	PRINT("%#01x", -42);
	PRINT("%#01x", 0);
	PRINT("%#01x", UINT_MAX);

	PRINT("%05.0x", 42);
	PRINT("%015.0x", -42);
	PRINT("%05.0x", 0);
	PRINT("%015.0x", UINT_MAX);

	PRINT("%#05.5x", 42);
	PRINT("%#015.0x", -42);
	PRINT("%#05.0x", 0);
	PRINT("%#015.0x", UINT_MAX);

	// teardown
	dup2(saved, 1);
	close(pipefd[0]);
	close(pipefd[1]);

	done_testing();
}
