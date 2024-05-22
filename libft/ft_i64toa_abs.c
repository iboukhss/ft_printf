/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i64toa_abs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:31:23 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/22 21:36:21 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>

static size_t	count_digits(int64_t v)
{
	size_t	cnt;

	if (!v)
		return (1);
	cnt = 0;
	while (v)
	{
		v /= 10;
		++cnt;
	}
	return (cnt);
}

int	ft_i64toa_abs(char *buf, int64_t val, size_t size)
{
	size_t	len;
	size_t	i;

	if (val > 0)
		val = -val;
	len = count_digits(val);
	if (len > size - 1)
		return (-E2BIG);
	i = len;
	buf[i] = '\0';
	while (i)
	{
		buf[--i] = '0' - (val % 10);
		val /= 10;
	}
	return (len);
}
