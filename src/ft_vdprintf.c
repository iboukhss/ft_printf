/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/13 06:11:08 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "ft_printf.h"
#include "libft.h"
#include "append.h"
#include "buffer.h"
#include "parse.h"

static const t_funptr	g_tab[256] = {
['%'] = append_char,
['c'] = append_char,
['s'] = append_str,
['p'] = append_ptr,
['d'] = append_int,
['i'] = append_int,
['u'] = append_uint,
['x'] = append_hex,
['X'] = append_hex,
};

static void	init_buffer(int fd, t_buffer *buf)
{
	ft_memset(buf, 0, sizeof(*buf));
	buf->fd = fd;
	buf->cap = sizeof(buf->data);
}

static void	init_format(t_format *f)
{
	ft_memset(f, 0, sizeof(*f));
	f->precision = -1;
}

static void	parse_format(const char **fmt, t_format *f)
{
	init_format(f);
	parse_flags(fmt, f);
	parse_width(fmt, f);
	parse_precision(fmt, f);
	f->specifier = **fmt;
	f->invalid |= (!g_tab[f->specifier]);
	check_format(f);
	if (f->invalid)
		errno = EINVAL;
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_buffer	buf;
	t_format	f;

	init_buffer(fd, &buf);
	while (*fmt && !buf.error)
	{
		if (*fmt == '%')
		{
			++fmt;
			parse_format(&fmt, &f);
			if (f.invalid)
				return (-1);
			g_tab[f.specifier](&buf, &f, ap);
		}
		else
		{
			buf_cpy(&buf, fmt, 1);
		}
		++fmt;
	}
	buf_flush(&buf);
	if (buf.error)
		return (-1);
	return (buf.cnt);
}
