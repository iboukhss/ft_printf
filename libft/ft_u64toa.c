/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 04:28:17 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/05 05:26:01 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(uint64_t val)
{
	int	count;

	count = 1;
	while (val > 9)
	{
		val /= 10;
		++count;
	}
	return (count);
}

int	ft_u64toa(uint64_t val, char *buf, size_t size)
{
	size_t	len;
	size_t	i;

	len = count_digits(val);
	if (size < len + 1)
		return (-1);
	buf[len] = '\0';
	i = len;
	while (i)
	{
		buf[--i] = '0' + (val % 10);
		val /= 10;
	}
	return (len);
}
