/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i32toa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:33 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/19 14:40:46 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/** Very efficient base-10 digit counting function using binary search.
 *  We use a bit hack to caclulate the absolute value of n without branching
 *  for even more optimization.
 *
 *  References:
 *  https://stackoverflow.com/a/1068966/23471454
 *  https://graphics.stanford.edu/~seander/bithacks.html#IntegerAbs
 */
static size_t	count_digits(int32_t n)
{
	size_t		ret;
	uint32_t	mask;
	uint32_t	val;

	mask = n >> 31;
	val = (n + mask) ^ mask;
	ret = 1;
	if (val >= 100000000)
	{
		ret += 8;
		val /= 100000000;
	}
	if (val >= 10000)
	{
		ret += 4;
		val /= 10000;
	}
	if (val >= 100)
	{
		ret += 2;
		val /= 100;
	}
	if (val >= 10)
		++ret;
	return (ret);
}

/** Custom version of itoa(), which is not standard in C.
 *  ft_i32toa() only supports base-10 conversion up to 32 bits integers.
 *  This function provides protection against buffer overflows, granted
 *  the proper size of the destination buffer is provided.
 *
 *  For 64 bits unsigned integers see ft_u64toa().
 */
char	*ft_i32toa(char *dst, int32_t val, size_t size)
{
	size_t	len;
	int		neg;

	neg = 0;
	len = count_digits(val);
	if (val < 0)
		neg = 1;
	else
		val = -val;
	if (size < len + neg + 1)
		return (NULL);
	if (!dst)
		return (NULL);
	dst[len + neg] = '\0';
	while (len--)
	{
		dst[len + neg] = '0' - (val % 10);
		val /= 10;
	}
	if (neg)
		dst[0] = '-';
	return (dst);
}
