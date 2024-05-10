/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i64toa_abs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:52:51 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/10 19:54:34 by iboukhss         ###   ########.fr       */
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

int	ft_i64toa_abs(int64_t val, char *buf, size_t size)
{
	size_t	len;
	size_t	i;

	if (val > 0)
		val = -val;
	len = count_digits(val);
	if (size < len)
		return (-1);
	i = len;
	while (i)
	{
		buf[--i] = '0' - (val % 10);
		val /= 10;
	}
	return (len);
}
