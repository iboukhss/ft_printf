/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:17:30 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/11 00:37:04 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits_hex(uint64_t val)
{
	size_t	count;

	if (!val)
		return (1);
	count = 0;
	while (val)
	{
		val >>= 4;
		++count;
	}
	return (count);
}

int	ft_u64toa_hex(uint64_t val, char *buf, size_t size, int lower)
{
	size_t		len;
	size_t		i;

	len = count_digits_hex(val);
	if (len > size)
		return (-1);
	i = len;
	while (i)
	{
		buf[--i] = "0123456789ABCDEF"[val & 15] | lower;
		val >>= 4;
	}
	return (len);
}
