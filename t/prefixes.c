/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefixes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:52:05 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/10 05:59:34 by iboukhss         ###   ########.fr       */
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

	diag("space ##################################");
	PRINT("% d", 42);
	PRINT("% d", -42);
	PRINT("% d", 0);
	PRINT("% d", INT_MIN);
	PRINT("% d", INT_MAX);

	diag("plus sign ##############################");
	PRINT("%+d", 42);
	PRINT("%+d", -42);
	PRINT("%+d", 0);
	PRINT("%+d", INT_MIN);
	PRINT("%+d", INT_MAX);

	// undefined behavior for %u

	diag("alt form ###############################");
	PRINT("%#x", 42);
	PRINT("%#x", -42);
	PRINT("%#x", 0);
	PRINT("%#x", UINT_MAX);

	PRINT("%#X", 42);
	PRINT("%#X", -42);
	PRINT("%#X", 0);
	PRINT("%#X", UINT_MAX);

	// teardown
	dup2(saved, 1);
	close(pipefd[0]);
	close(pipefd[1]);

	done_testing();
}
