/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:55:08 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/03 23:46:02 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	ft_ulltoa(unsigned long long val, char *buf, size_t size, int base)
{
	char	*end;
	char	*beg;
	t_str	s;

	end = buf + size;
	beg = end;
	while (size--)
	{
		*--beg = "0123456789abcdef"[val % base];
		val /= base;
		if (!val)
			break ;
	}
	s.data = (unsigned char *)beg;
	s.len = end - beg;
	return (s);
}
