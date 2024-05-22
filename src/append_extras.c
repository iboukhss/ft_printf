/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/22 16:05:58 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "append.h"
#include "buffer.h"

/* Buffer size for INT64_MAX (9223372036854775807): 19 bytes + null */
void	append_int(t_buffer *buf, t_format *f, va_list ap)
{
	char	tmp[20];
	char	pfx[2];
	t_print	p;
	int		n;

	ft_memset(&p, 0, sizeof(p));
	n = va_arg(ap, int);
	if (!n && !f->precision)
		p.slen = 0;
	else
		p.slen = ft_i64toa_abs(tmp, n, sizeof(tmp));
	if (n < 0)
		p.plen = ft_strscpy(pfx, "-", sizeof(pfx));
	else if (f->show_pos)
		p.plen = ft_strscpy(pfx, "+", sizeof(pfx));
	else if (f->hide_pos)
		p.plen = ft_strscpy(pfx, " ", sizeof(pfx));
	p.str = tmp;
	p.pfx = pfx;
	get_padding(&p, f);
	append_pri(buf, &p);
}

/* Buffer size for UINT64_MAX (18446744073709551615): 20 bytes + null */
void	append_uint(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[21];
	t_print			pri;
	unsigned int	u;

	ft_memset(&pri, 0, sizeof(pri));
	u = va_arg(ap, unsigned int);
	if (!u && !f->precision)
		pri.slen = 0;
	else
		pri.slen = ft_u64toa(tmp, u, sizeof(tmp));
	pri.str = tmp;
	get_padding(&pri, f);
	append_pri(buf, &pri);
}

/* Buffer size for UINT64_MAX (0xffffffffffffffff) 16 bytes + null */
void	append_hex(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[17];
	char			pfx[3];
	t_print			p;
	unsigned int	x;

	ft_memset(&p, 0, sizeof(p));
	x = va_arg(ap, unsigned int);
	if (!x && !f->precision)
		p.slen = 0;
	else
		p.slen = ft_u64toa_hex(tmp, x, sizeof(tmp));
	if (x && f->alt_form)
	{
		if (f->specifier == 'x')
			p.plen = ft_strscpy(pfx, "0x", sizeof(pfx));
		if (f->specifier == 'X')
			p.plen = ft_strscpy(pfx, "0X", sizeof(pfx));
	}
	if (f->specifier == 'X')
		p.str = ft_strupr(tmp);
	else
		p.str = tmp;
	p.pfx = pfx;
	get_padding(&p, f);
	append_pri(buf, &p);
}
