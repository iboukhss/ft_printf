/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/13 07:02:40 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "append.h"
#include "buffer.h"

void	append_int(t_buffer *buf, t_format *f, va_list ap)
{
	char	tmp[64];
	int		len;
	int		pad;
	int		n;

	n = va_arg(ap, int);
	len = ft_i64toa_abs(n, tmp, sizeof(tmp));
	if (!n && !f->precision)
		len = 0;
	if (n < 0)
		pad = append_prefix(buf, f, len, "-");
	else if (f->show_pos)
		pad = append_prefix(buf, f, len, "+");
	else if (f->hide_pos)
		pad = append_prefix(buf, f, len, " ");
	else
		pad = append_prefix(buf, f, len, "\0");
	buf_cpy(buf, tmp, len);
	buf_set(buf, ' ', pad);
}

void	append_uint(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[64];
	int				len;
	int				pad;
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	len = ft_u64toa(u, tmp, sizeof(tmp));
	if (!u && !f->precision)
		len = 0;
	pad = append_prefix(buf, f, len, "\0");
	buf_cpy(buf, tmp, len);
	buf_set(buf, ' ', pad);
}

void	append_hex(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[64];
	int				len;
	int				pad;
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	len = ft_u64toa_hex(x, tmp, sizeof(tmp), f->specifier & 32);
	if (!x && !f->precision)
		len = 0;
	if (f->specifier == 'x' && f->alt_form && x)
		pad = append_prefix(buf, f, len, "0x");
	else if (f->specifier == 'X' && f->alt_form && x)
		pad = append_prefix(buf, f, len, "0X");
	else
		pad = append_prefix(buf, f, len, "\0");
	buf_cpy(buf, tmp, len);
	buf_set(buf, ' ', pad);
}
