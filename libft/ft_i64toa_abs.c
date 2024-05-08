/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i64toa_abs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:22:31 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 03:01:50 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int64_t val)
{
	size_t	count;

	count = 1;
	while (val < -9)
	{
		val /= 10;
		++count;
	}
	return (count);
}

int	ft_i64toa_abs(int64_t val, char *buf, size_t size)
{
	size_t	len;
	size_t	i;

	if (val > 0)
		val = -val;
	len = count_digits(val);
	if (len > size)
		return (-1);
	i = len;
	while (i)
	{
		buf[--i] = '0' - (val % 10);
		val /= 10;
	}
	return (len);
}
