/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/10 21:38:54 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "libft.h"

static const char	*parse_prefix(t_format *f, int val)
{
	if (f->specifier == 'd' || f->specifier == 'i')
	{
		if (val < 0)
			return ("-");
		else if (f->show_pos)
			return ("+");
		else if (f->hide_pos)
			return (" ");
	}
	else if (f->specifier == 'x' && f->alt_form && val)
		return ("0x");
	else if (f->specifier == 'X' && f->alt_form && val)
		return ("0X");
	return ("\0");
}

static void	append_left(t_buffer *buf, t_format *f, int len, const char *prefix)
{
	int		pad;
	int		wid;
	int		offset;

	offset = ft_strlen(prefix);

	pad = 0;
	if (f->precision > len)
		pad = f->precision - len;					// offset could be 0, 1 or 2
	wid = 0;
	if (f->width > len + pad + offset)
		wid = f->width - (len + pad + offset);		// len + pad + offset represents the entire prefix len

	if (!f->left_adj)
		fill(buf, ' ', wid);

	append(buf, prefix, offset);
	fill(buf, '0', pad);
}

void	append_ptr(t_buffer *buf, t_format *f, va_list ap)
{
	char		tmp[64];
	size_t		len;
	uintptr_t	p;

	(void)f;
	p = va_arg(ap, uintptr_t);
	if (!p)
		return (append(buf, "(nil)", 5));
	len = ft_u64toa_base(p, tmp, sizeof(tmp), HEX);
	append_left(buf, f, len, "0x");
	append(buf, tmp, len);
}

void	append_int(t_buffer *buf, t_format *f, va_list ap)
{
	char		tmp[64];
	int			len;
	int			n;
	const char	*prefix;

	n = va_arg(ap, int);
	prefix = parse_prefix(f, n);
	len = ft_i64toa_abs(n, tmp, sizeof(tmp));
	append_left(buf, f, len, prefix);
	if (!n && !f->precision)
		return ;
	append(buf, tmp, len);
}

void	append_uint(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[64];
	int				len;
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	if (!u && !f->precision)
		return ;
	len = ft_u64toa(u, tmp, sizeof(tmp));
	append_left(buf, f, len, "\0");
	append(buf, tmp, len);
}

void	append_hex(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[64];
	int				len;
	unsigned int	x;
	const char		*prefix;

	x = va_arg(ap, unsigned int);
	if (!x && !f->precision)
		return ;
	prefix = parse_prefix(f, x);
	len = ft_u64toa_base(x, tmp, sizeof(tmp), f->specifier);
	append_left(buf, f, len, prefix);
	append(buf, tmp, len);
}
