/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:41:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/22 21:39:23 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "buffer.h"

#include "libft.h"

/* We check for slen != 0 only for the edge case where precision is used with
 * a NULL string pointer. We probably shouldn't have to handle this, but it
 * helps us match GNU printf behavior more closely.
 */
void	get_padding(t_print *p, t_format *f)
{
	if (p->slen && f->precision > p->slen)
		p->zpad = f->precision - p->slen;
	if (f->width > p->plen + p->zpad + p->slen)
		p->lpad = f->width - (p->plen + p->zpad + p->slen);
	if (f->left_adj)
	{
		p->rpad = p->lpad;
		p->lpad = 0;
	}
	else if (f->zero_pad && f->precision == -1)
	{
		p->zpad += p->lpad;
		p->lpad = 0;
	}
}

void	append_pri(t_buffer *buf, t_print *p)
{
	buf_set(buf, ' ', p->lpad);
	buf_cpy(buf, p->pfx, p->plen);
	buf_set(buf, '0', p->zpad);
	buf_cpy(buf, p->str, p->slen);
	buf_set(buf, ' ', p->rpad);
}

void	append_char(t_buffer *buf, t_format *f, va_list ap)
{
	t_print	p;
	char	c;

	ft_memset(&p, 0, sizeof(p));
	if (f->specifier == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	p.slen = 1;
	p.str = &c;
	get_padding(&p, f);
	append_pri(buf, &p);
}

void	append_str(t_buffer *buf, t_format *f, va_list ap)
{
	t_print	p;
	char	*str;

	ft_memset(&p, 0, sizeof(p));
	str = va_arg(ap, char *);
	if (!str)
		p.str = "(null)";
	else
		p.str = str;
	if (!str && (f->precision > 0 && f->precision < 6))
		p.slen = 0;
	else if (f->precision >= 0)
		p.slen = ft_strnlen(p.str, f->precision);
	else
		p.slen = ft_strlen(p.str);
	get_padding(&p, f);
	append_pri(buf, &p);
}

/* Buffer size for UINT64_MAX (0xffffffffffffffff) 16 bytes + null */
void	append_ptr(t_buffer *buf, t_format *f, va_list ap)
{
	char		tmp[17];
	char		pfx[3];
	t_print		p;
	uintptr_t	ptr;

	ft_memset(&p, 0, sizeof(p));
	ptr = (uintptr_t)va_arg(ap, void *);
	if (!ptr)
		p.slen = ft_strscpy(tmp, "(nil)", sizeof(tmp));
	else
	{
		p.plen = ft_strscpy(pfx, "0x", sizeof(pfx));
		p.slen = ft_u64toa_hex(tmp, ptr, sizeof(tmp));
	}
	p.str = tmp;
	p.pfx = pfx;
	get_padding(&p, f);
	append_pri(buf, &p);
}
