/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:00:22 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/29 02:19:41 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_utoa(unsigned char *dst, unsigned int val, size_t size)
{
	if (size < 2)
		return (NULL);
	dst[--size] = '\0';
	while (size)
	{
		dst[--size] = '0' + (val % 10);
		val /= 10;
		if (!val)
			break ;
	}
	if (val)
		return (NULL);
	return (dst + size);
}
