/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:10:28 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/29 02:18:16 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_itoa(unsigned char *dst, int val, size_t size)
{
	bool	neg;

	neg = false;
	if (size < 2)
		return (NULL);
	if (val < 0)
		neg = true;
	else
		val = -val;
	dst[--size] = '\0';
	while (size)
	{
		dst[--size] = '0' - (val % 10);
		val /= 10;
		if (!val)
			break ;
	}
	if (val || (neg && !size))
		return (NULL);
	if (neg)
		dst[--size] = '-';
	return (dst + size);
}
