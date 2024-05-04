/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 20:32:49 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"

void	append_uint(t_buffer *b, t_format *f, va_list ap)
{
	char			tmp[64];
	size_t			i;
	unsigned int	u;

	(void)f;
	i = sizeof(tmp);
	u = va_arg(ap, unsigned int);
	while (i)
	{
		tmp[--i] = '0' + (u % 10);
		u /= 10;
		if (!u)
			break ;
	}
	append(b, tmp + i, sizeof(tmp) - i);
}

void	append_hex(t_buffer *b, t_format *f, va_list ap)
{
	char			tmp[64];
	size_t			i;
	unsigned int	x;
	int				lower;

	i = sizeof(tmp);
	x = va_arg(ap, unsigned int);
	lower = (f->specifier & 0x20);
	while (i)
	{
		tmp[--i] = "0123456789ABCDEF"[x & 15] | lower;
		x >>= 4;
		if (!x)
			break ;
	}
	append(b, tmp + i, sizeof(tmp) - i);
}
