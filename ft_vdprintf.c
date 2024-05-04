/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 19:46:56 by iboukhss         ###   ########.fr       */
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

static const char	*parse_format(const char **fmt, t_format *data)
{
	const char	*ptr;

	// initialize
	ft_memset(data, 0, sizeof(*data));
	data->precision = -1;

	// get pointer
	ptr = *fmt;

	// skip over
	++ptr;

	if (*ptr == '\0')
		return (ptr);

	// parse flags
	while (*ptr)
	{
		if (*ptr == '#')
			data->alt_form = *ptr;
		else if (*ptr == '0')
			data->zero_pad = *ptr;
		else if (*ptr == '-')
			data->left_adj = *ptr;
		else if (*ptr == ' ')
			data->blank_sign = *ptr;
		else if (*ptr == '+')
			data->plus_sign = *ptr;
		else
			break ;
		++ptr;
	}

	// parse width
	while (ft_isdigit(*ptr))
	{
		data->width = data->width * 10 + (*ptr - '0');
		++ptr;
	}

	// parse precision
	if (*ptr == '.')
	{
		// skip over
		++ptr;

		if (*ptr == '\0' || *ptr == '-')
			return (ptr);

		while (ft_isdigit(*ptr))
		{
			data->precision = data->precision * 10 + (*ptr - '0');
			++ptr;
		}
	}

	// parse specifier
	data->specifier = *ptr;

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
			g_tab[(unsigned char)*fmt](&buf, &f, ap);
			// keep going?
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
