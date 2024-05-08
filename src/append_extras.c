/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 23:12:32 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "libft.h"

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
	append(buf, "0x", 2);
	append(buf, tmp, len);
}

void	append_int(t_buffer *buf, t_format *f, va_list ap)
{
	char	tmp[64];
	size_t	len;
	int		n;

	n = va_arg(ap, int);
	if (!n && !f->precision)
		return ;
	len = ft_i64toa(n, tmp, sizeof(tmp));
	if (n < 0)
		;
	else if (f->show_pos)
		append(buf, "+", 1);
	else if (f->hide_pos)
		append(buf, " ", 1);
	append(buf, tmp, len);
}

void	append_uint(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[64];
	size_t			len;
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	len = ft_u64toa(u, tmp, sizeof(tmp));
	if (f->show_pos)
		append(buf, "+", 1);
	else if (f->hide_pos)
		append(buf, " ", 1);
	append(buf, tmp, len);
}

void	append_hex(t_buffer *buf, t_format *f, va_list ap)
{
	char			tmp[64];
	size_t			len;
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	len = ft_u64toa_base(x, tmp, sizeof(tmp), f->specifier);
	if (x && f->alt_form)
	{
		append(buf, "0", 1);
		append(buf, &f->specifier, 1);
	}
	append(buf, tmp, len);
}
