/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:23:32 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/22 21:36:37 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>

static size_t	count_digits_hex(uint64_t v)
{
	size_t	cnt;

	if (!v)
		return (1);
	cnt = 0;
	while (v)
	{
		v /= 16;
		++cnt;
	}
	return (cnt);
}

int	ft_u64toa_hex(char *buf, uint64_t val, size_t size)
{
	size_t	len;
	size_t	i;

	len = count_digits_hex(val);
	if (len > size - 1)
		return (-E2BIG);
	i = len;
	buf[i] = '\0';
	while (i)
	{
		buf[--i] = "0123456789abcdef"[val % 16];
		val /= 16;
	}
	return (len);
}
