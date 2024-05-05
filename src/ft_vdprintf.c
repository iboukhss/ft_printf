/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/05 23:43:20 by iboukhss         ###   ########.fr       */
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

static void	init_buffer(int fd, t_buffer *buf)
{
	ft_memset(buf, 0, sizeof(*buf));
	buf->fd = fd;
}

static const char	*parse_format(const char **fmt, t_format *f)
{
	const char	*ptr;

	ft_memset(f, 0, sizeof(*f));
	f->precision = -1;
	ptr = *fmt;
	if (*++ptr == '\0')
	{
		f->invalid = 1;
		return (ptr);
	}
	ptr = parse_flags(&ptr, f);
	ptr = parse_width(&ptr, f);
	f->specifier = *ptr;
	f->invalid |= !g_tab[(unsigned char)*ptr];
	return (ptr);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_format	f;
	t_buffer	buf;

	init_buffer(fd, &buf);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt = parse_format(&fmt, &f);
			if (f.invalid)
				return (-1);
			g_tab[(unsigned char)*fmt](&buf, &f, ap);
		}
		else
		{
			append(&buf, fmt, 1);
		}
		if (buf.error)
			return (-1);
		++fmt;
	}
	flush(&buf);
	if (buf.error)
		return (-1);
	return (buf.cnt);
}
