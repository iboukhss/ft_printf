/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/11 08:59:24 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "libft.h"
#include <stdint.h>

int	append_pad(t_buffer *buf, t_format *f, int len, const char *prefix)
{
	int	pad;
	int	wid;
	int	offset;

	offset = ft_strlen(prefix);
	pad = 0;
	if (f->precision > len && f->specifier != 'p')
		pad = f->precision - len;
	wid = 0;
	if (f->width > len + pad + offset)
		wid = f->width - (len + pad + offset);
	if (f->left_adj)
	{
		append(buf, prefix, offset);
		fill(buf, '0', pad);
		return (wid);
	}
	else if (f->zero_pad && f->precision < 0)
	{
		append(buf, prefix, offset);
		fill(buf, '0', wid);
	}
	else
	{
		fill(buf, ' ', wid);
		append(buf, prefix, offset);
		fill(buf, '0', pad);
	}
	return (0);
}

void	append_ptr(t_buffer *buf, t_format *f, va_list ap)
{
	char		tmp[64];
	int			len;
	int			wid;
	uintptr_t	p;

	p = va_arg(ap, uintptr_t);
	len = ft_u64toa_hex(p, tmp, sizeof(tmp), f->specifier & 32);
	if (!p)
		wid = append_pad(buf, f, 0, "(nil)");
	else
	{
		wid = append_pad(buf, f, len, "0x");
		append(buf, tmp, len);
	}
	fill(buf, ' ', wid);
}

void	append_int(t_buffer *buf, t_format *f, va_list ap)
{
	char	tmp[64];
	int		len;
	int		wid;
	int		n;

	n = va_arg(ap, int);
	len = ft_i64toa_abs(n, tmp, sizeof(tmp));
	if (!n && !f->precision)
		len = 0;
	if (n < 0)
		wid = append_pad(buf, f, len, "-");
	else if (f->show_pos)
		wid = append_pad(buf, f, len, "+");
	else if (f->hide_pos)
		wid = append_pad(buf, f, len, " ");
	else
		wid = append_pad(buf, f, len, "\0");
	append(buf, tmp, len);
	fill(buf, ' ', wid);
}

void	append_uint(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[64];
	int				len;
	int				wid;
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	len = ft_u64toa(u, tmp, sizeof(tmp));
	if (!u && !f->precision)
		len = 0;
	wid = append_pad(buf, f, len, "\0");
	append(buf, tmp, len);
	fill(buf, ' ', wid);
}

void	append_hex(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[64];
	int				len;
	int				wid;
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	len = ft_u64toa_hex(x, tmp, sizeof(tmp), f->specifier & 32);
	if (!x && !f->precision)
		len = 0;
	if (f->specifier == 'x' && f->alt_form && x)
		wid = append_pad(buf, f, len, "0x");
	else if (f->specifier == 'X' && f->alt_form && x)
		wid = append_pad(buf, f, len, "0X");
	else
		wid = append_pad(buf, f, len, "\0");
	append(buf, tmp, len);
	fill(buf, ' ', wid);
}
