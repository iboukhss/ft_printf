/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:19:28 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/03 23:27:02 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	ft_itoa(int val, char *buf, size_t size)
{
	int		neg;
	char	*end;
	char	*beg;
	t_str	s;

	neg = 0;
	if (val < 0)
		neg = 1;
	else
		val = -val;
	end = buf + size;
	beg = end;
	while (size--)
	{
		*--beg = '0' - (val % 10);
		val /= 10;
		if (!val)
			break ;
	}
	if (neg)
		*--beg = '-';
	s.data = (unsigned char *)beg;
	s.len = end - beg;
	return (s);
}
