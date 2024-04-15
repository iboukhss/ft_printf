/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i32toa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:33 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/16 00:57:23 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/** Very fast base-10 digit counting function using binary search.
 *  We work with negative numbers to avoid integer overflow on INT_MIN.
 *  https://stackoverflow.com/a/1068937/23471454
 */
static size_t	count_digits(int32_t n)
{
	size_t	r;

	r = 1;
	if (n > 0)
		n = -n;
	if (n <= -100000000)
	{
		r += 8;
		n /= 100000000;
	}
	if (n <= -10000)
	{
		r += 4;
		n /= 10000;
	}
	if (n <= -100)
	{
		r += 2;
		n /= 100;
	}
	if (n <= -10)
		++r;
	return (r);
}

/** Custom version of itoa(), which is not standard in C.
 *  ft_i32toa() only supports base-10 conversion up to 32 bit integers.
 *  This function provides protection against buffer overflows, granted
 *  the proper size of the destination buffer is provided.
 *
 *  For base-16 conversion and 64 bit unsigned integers see ft_u64toa().
 */
char	*ft_i32toa(char *dst, size_t size, int32_t val)
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
