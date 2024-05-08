/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i64toa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:19:08 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 17:57:02 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int64_t val)
{
	size_t	count;

	count = 0;
	if (val == 0)
		return (1);
	while (val)
	{
		val /= 10;
		++count;
	}
	return (count);
}

int	ft_i64toa(int64_t val, char *buf, size_t size)
{
	int		neg;
	size_t	len;
	size_t	i;

	neg = 0;
	len = count_digits(val);
	if (val < 0)
		neg = 1;
	else
		val = -val;
	if (size < len + neg)
		return (-1);
	i = len + neg;
	while (i)
	{
		buf[--i] = '0' - (val % 10);
		val /= 10;
	}
	if (neg)
		buf[0] = '-';
	return (len + neg);
}
