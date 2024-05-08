/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 10:27:58 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "libft.h"

void	append_int(t_buffer *buf, t_format *f, va_list ap)
{
	char	tmp[64];
	size_t	len;
	int		i;

	i = va_arg(ap, int);
	len = ft_i64toa_abs(i, tmp, sizeof(tmp));
	if (i < 0)
		append(buf, "-", 1);
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
