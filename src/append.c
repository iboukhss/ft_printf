/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:41:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/13 07:02:39 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "append.h"
#include "buffer.h"
#include <stdint.h>

size_t	count_padding(t_format *f, int len, int offset)
{
	// TODO: refactor append_pad
}

int	append_prefix(t_buffer *buf, t_format *f, int len, const char *prefix)
{
	int	pre;
	int	wid;
	int	offset;

	pre = 0;
	wid = 0;
	offset = ft_strlen(prefix);
	if (len && f->precision > len)
		pre = f->precision - len;
	if (f->width > len + pre + offset)
		wid = f->width - (len + pre + offset);
	if (f->left_adj)
	{
		buf_cpy(buf, prefix, offset);
		buf_set(buf, '0', pre);
		return (wid);
	}
	else if (f->zero_pad && f->precision == -1)
	{
		buf_cpy(buf, prefix, offset);
		buf_set(buf, '0', wid);
	}
	else
	{
		buf_set(buf, ' ', wid);
		buf_cpy(buf, prefix, offset);
		buf_set(buf, '0', pre);
	}
	return (0);
}

void	append_char(t_buffer *buf, t_format *f, va_list ap)
{
	int				pad;
	unsigned char	c;

	if (f->specifier == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(ap, int);
	pad = append_prefix(buf, f, 1, "\0");
	buf_cpy(buf, &c, 1);
	buf_set(buf, ' ', pad);
}

void	append_str(t_buffer *buf, t_format *f, va_list ap)
{
	int		len;
	int		pad;
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		s = "(null)";
		len = ft_strlen(s);
	}
	else if (f->precision >= 0)
		len = ft_strnlen(s, f->precision);
	else
		len = ft_strlen(s);
	pad = append_prefix(buf, f, len, "\0");
	buf_cpy(buf, s, len);
	buf_set(buf, ' ', pad);
}

void	append_ptr(t_buffer *buf, t_format *f, va_list ap)
{
	char		tmp[64];
	int			len;
	int			pad;
	uintptr_t	p;

	p = (uintptr_t)va_arg(ap, void *);
	if (!p)
		pad = append_prefix(buf, f, 0, "(nil)");
	else
	{
		len = ft_u64toa_hex(p, tmp, sizeof(tmp), f->specifier & 32);
		pad = append_prefix(buf, f, len, "0x");
		buf_cpy(buf, tmp, len);
	}
	buf_set(buf, ' ', pad);
}
