/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 19:48:43 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"

void	append_uint(t_buffer *b, t_format *f, va_list ap)
{
	char			tmp[64];
	char			*beg;
	char			*end;
	unsigned int	u;

	(void)f;
	u = va_arg(ap, unsigned int);
	end = tmp + sizeof(tmp);
	beg = end;
	while (u)
	{
		*--beg = '0' + (u % 10);
		u /= 10;
	}
	append(b, beg, end - beg);
}

void	append_hex(t_buffer *b, t_format *f, va_list ap)
{
	char			tmp[64];
	char			*beg;
	char			*end;
	unsigned int	x;
	int				lower;

	lower = (f->specifier & 0x20);
	x = va_arg(ap, unsigned int);
	end = tmp + sizeof(tmp);
	beg = end;
	while (x)
	{
		*--beg = "0123456789ABCDEF"[x & 15] | lower;
		x >>= 4;
	}
	append(b, beg, end - beg);
}
