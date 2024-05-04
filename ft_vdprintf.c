/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 23:06:14 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "append.h"

static const t_funptr	g_tab[256] = {
['%'] = append_byte,
['c'] = append_byte,
['s'] = append_str,
['p'] = append_ptr,
['d'] = append_int,
['i'] = append_int,
//['b'] = append_bin,
//['o'] = append_oct,
['u'] = append_uint,
['x'] = append_hex,
['X'] = append_hex,
};

static const char	*parse_format(const char **fmt, t_format *f)
{
	const char	*ptr;

	ft_memset(f, 0, sizeof(*f));
	f->precision = -1;

	// get pointer
	ptr = *fmt;

	// skip over
	++ptr;

	if (*ptr == '\0')
	{
		f->invalid = 1;
		return (ptr);
	}

	// parse flags
	while (*ptr)
	{
		if (*ptr == '#')
			f->alt_form = *ptr;
		else if (*ptr == '0')
			f->zero_pad = *ptr;
		else if (*ptr == '-')
			f->left_adj = *ptr;
		else if (*ptr == ' ')
			f->blank_sign = *ptr;
		else if (*ptr == '+')
			f->plus_sign = *ptr;
		else
			break ;
		++ptr;
	}

	// parse width
	while (ft_isdigit(*ptr))
	{
		f->width = f->width * 10 + (*ptr - '0');
		++ptr;
	}

	// parse precision
	if (*ptr == '.')
	{
		f->precision = 0;

		// skip over
		++ptr;

		if (*ptr == '\0' || *ptr == '-')
		{
			f->invalid = 1;
			return (ptr);
		}

		while (ft_isdigit(*ptr))
		{
			f->precision = f->precision * 10 + (*ptr - '0');
			++ptr;
		}
	}

	// parse specifier
	if (!g_tab[(unsigned char)*ptr])
	{
		f->invalid = 1;
		return (ptr);
	}

	f->specifier = *ptr;

	return (ptr);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_format	f;
	t_buffer	buf;

	ft_memset(&buf, 0, sizeof(buf));
	buf.cap = sizeof(buf.data);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt = parse_format(&fmt, &f);
			if (f.invalid)
				return (-1);
			g_tab[(unsigned char)*fmt](&buf, &f, ap);
			++fmt;
		}
		else
		{
			append(&buf, fmt, 1);
			++fmt;
		}
		if (buf.full)
			break ;
	}
	write(fd, buf.data, buf.len);
	return (buf.len);
}
