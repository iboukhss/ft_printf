/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:13:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/19 15:20:20 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/** This is the best solution I could come up with under 25 lines that manages
 *  to pass norminette. This results in the following abomination, which,
 *  suprisingly, performs almost indentically to "normally written" code using
 *  half as many conditionals.
 */
static size_t	count_digits(uint64_t n)
{
	size_t	r;

	r = 1;
	if (n >= 10000000000000000LL)
		r += 16;
	if (n >= 10000000000000000LL)
		n /= 10000000000000000LL;
	if (n >= 100000000L)
		r += 8;
	if (n >= 100000000L)
		n /= 100000000L;
	if (n >= 10000)
		r += 4;
	if (n >= 10000)
		n /= 10000;
	if (n >= 100)
		r += 2;
	if (n >= 100)
		n /= 100;
	if (n >= 10)
		++r;
	return (r);
}

char	*ft_u64toa(char *dst, uint64_t val, size_t size)
{
	size_t	len;

	len = count_digits(val);
	if (size < len + 1)
		return (NULL);
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	while (len--)
	{
		dst[len] = '0' + (val % 10);
		val /= 10;
	}
	return (dst);
}
