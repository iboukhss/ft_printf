/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/05 20:22:26 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse.h"
#include "append.h"
#include "libft.h"

static const t_funptr	g_tab[256] = {
['%'] = append_byte,
['c'] = append_byte,
['s'] = append_str,
['p'] = append_ptr,
['d'] = append_int,
['i'] = append_int,
['u'] = append_uint,
['x'] = append_hex,
['X'] = append_hex,
};

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_format	f;
	t_buffer	buf;

	ft_memset(&buf, 0, sizeof(buf));
	buf.fd = fd;
	buf.cap = sizeof(buf.data);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt = parse_format(&fmt, &f);
			if (f.invalid || !g_tab[(unsigned char)*fmt])
				return (-1);
			g_tab[(unsigned char)*fmt](&buf, &f, ap);
			++fmt;
		}
		else
		{
			append(&buf, fmt, 1);
			++fmt;
		}
	}
	flush(&buf);
	return (buf.cnt);
}
