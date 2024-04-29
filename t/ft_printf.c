/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:15:15 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/28 23:31:38 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tap.h"

#include <string.h>
#include <limits.h>

typedef struct s_buf {
	char buf1[80];
	char buf2[80];
} t_buf;

#define TEST_CASE(format, ...) do {						\
	memset(&b, 0, sizeof(b));							\
	ft_printf(format, ##__VA_ARGS__);					\
	read(pipefd[0], b.buf1, sizeof(b.buf1));			\
	len = sprintf(b.buf2, format, ##__VA_ARGS__);		\
} while(0)

#define PRINT_BUFFER(buf, size) do {					\
	fprintf(stderr, "%08zu: |", size);					\
	for (size_t x = 0; x < size; ++x) {					\
		if (buf[x] == '\n')								\
			fprintf(stderr, "$");						\
		else if (buf[x] < ' ' || buf[x] > '~')			\
			fprintf(stderr, ".");						\
		else											\
			fprintf(stderr, "%c", buf[x]);				\
	}													\
	fprintf(stderr, "|\n");								\
} while (0)

int	main(void)
{
	plan(NO_PLAN);

	// initialize variables
	int len;
	int pipefd[2];
	t_buf b;

	// setup stdout redirection
	pipe(pipefd);
	int saved = dup(1);
	dup2(pipefd[1], 1);

	TEST_CASE("hello world!");
	cmp_mem(b.buf1, b.buf2, len, "string literal");

	TEST_CASE("%c%c%c", 'A', 'b', 'c');
	cmp_mem(b.buf1, b.buf2, len, "char");

	TEST_CASE("%d", INT_MAX);
	cmp_mem(b.buf1, b.buf2, len, "int max");

	TEST_CASE("%i", INT_MIN);
	cmp_mem(b.buf1, b.buf2, len, "int min");

	// teardown
	dup2(saved, 1);
	close(pipefd[0]);
	close(pipefd[1]);

	done_testing();
}
