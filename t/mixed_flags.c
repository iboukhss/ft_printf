/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:25:59 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/10 18:19:06 by iboukhss         ###   ########.fr       */
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
	PRINT("% 10.5d", 42);
	PRINT("% 10.5d", -42);
	PRINT("% 10.5d", 0);
	PRINT("% 20.15d", INT_MIN);
	PRINT("% 20.15d", INT_MAX);

	PRINT("% 0.1d", 42);
	PRINT("% 0.1d", -42);
	PRINT("% 0.1d", 0);
	PRINT("% 0.1d", INT_MIN);
	PRINT("% 0.1d", INT_MAX);

	PRINT("% 0.0d", 42);
	PRINT("% 0.0d", -42);
	PRINT("% 0.0d", 0);
	PRINT("% 0.0d", INT_MIN);
	PRINT("% 0.0d", INT_MAX);

	PRINT("%+10.5d", 42);
	PRINT("%+10.5d", -42);
	PRINT("%+10.5d", 0);
	PRINT("%+20.15d", INT_MIN);
	PRINT("%+20.15d", INT_MAX);

	PRINT("%+0.1d", 42);
	PRINT("%+0.1d", -42);
	PRINT("%+0.1d", 0);
	PRINT("%+0.1d", INT_MIN);
	PRINT("%+0.1d", INT_MAX);

	PRINT("%+0.0d", 42);
	PRINT("%+0.0d", -42);
	PRINT("%+0.0d", 0);
	PRINT("%+0.0d", INT_MIN);
	PRINT("%+0.0d", INT_MAX);

	diag("unsigned int ###########################");
	PRINT("%10.5u", 42);
	PRINT("%10.5u", -42);
	PRINT("%10.5u", 0);
	PRINT("%20.15u", UINT_MAX);

	PRINT("%0.1u", 42);
	PRINT("%0.1u", -42);
	PRINT("%0.1u", 0);
	PRINT("%0.1u", UINT_MAX);

	PRINT("%0.0u", 42);
	PRINT("%0.0u", -42);
	PRINT("%0.0u", 0);
	PRINT("%0.0u", UINT_MAX);

	diag("hexadecimal ############################");
	PRINT("%#10.5x", 42);
	PRINT("%#10.5x", -42);
	PRINT("%#10.5x", 0);
	PRINT("%#20.15x", UINT_MAX);

	PRINT("%#0.1x", 42);
	PRINT("%#0.1x", -42);
	PRINT("%#0.1x", 0);
	PRINT("%#0.1x", UINT_MAX);

	PRINT("%#0.0x", 42);
	PRINT("%#0.0x", -42);
	PRINT("%#0.0x", 0);
	PRINT("%#0.0x", UINT_MAX);


	PRINT("%#10.5X", 42);
	PRINT("%#10.5X", -42);
	PRINT("%#10.5X", 0);
	PRINT("%#20.15X", UINT_MAX);

	PRINT("%#0.1X", 42);
	PRINT("%#0.1X", -42);
	PRINT("%#0.1X", 0);
	PRINT("%#0.1X", UINT_MAX);

	PRINT("%#0.0X", 42);
	PRINT("%#0.0X", -42);
	PRINT("%#0.0X", 0);
	PRINT("%#0.0X", UINT_MAX);

	// teardown
	dup2(saved, 1);
	close(pipefd[0]);
	close(pipefd[1]);

	done_testing();
}
