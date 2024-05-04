/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 04:40:57 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static const t_funptr	g_tab[256] = {
['%'] = write_chr,
['c'] = write_chr,
['s'] = write_cstr,
['p'] = write_ptr,
['d'] = write_int,
['i'] = write_int,
['b'] = write_uint_base,
['o'] = write_uint_base,
['u'] = write_uint_base,
['x'] = write_uint_base,
['X'] = write_hex,
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
	int			cnt;

	cnt = 0;
	while (*fmt)
	{
		// specifier
		if (*fmt == '%')
		{
			fmt = parse_format(&fmt, &f);
			cnt += g_tab[(unsigned char)*fmt](fd, &f, ap);
			// keep going?
			++fmt;
		}
		// literal
		else
		{
			cnt += write(fd, fmt, 1);
			++fmt;
		}
	}
	return (cnt);
}

int	write_chr(int fd, t_format *f, va_list ap)
{
	int	c;

	if (f->specifier == '%')
		return (write(fd, "%", 1));
	c = va_arg(ap, int);
	return (write(fd, &c, 1));
}

int	write_cstr(int fd, t_format *f, va_list ap)
{
	char	*s;

	(void)f;
	s = va_arg(ap, char *);
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	write_ptr(int fd, t_format *f, va_list ap)
{
	char		buf[64];
	uintptr_t	p;
	t_str		s;

	(void)f;
	p = va_arg(ap, uintptr_t);
	if (!p)
		return (write(fd, "(nil)", 5));
	s = ft_ulltoa(p, buf, sizeof(buf), 16);
	return (write(fd, s.data, s.len));
}

int	write_int(int fd, t_format *f, va_list ap)
{
	char	buf[64];
	int		i;
	t_str	s;

	(void)f;
	i = va_arg(ap, int);
	s = ft_itoa(i, buf, sizeof(buf));
	return (write(fd, s.data, s.len));
}

int	write_uint_base(int fd, t_format *f, va_list ap)
{
	char			buf[64];
	unsigned int	u;
	int				base;
	t_str			s;
	int				c;

	c = f->specifier;
	if (c == 'b' || c == 'B')
		base = 2;
	else if (c == 'o')
		base = 8;
	else if (c == 'u')
		base = 10;
	else if (c == 'x' || c == 'X')
		base = 16;
	else
		return (-1);

	u = va_arg(ap, unsigned int);
	s = ft_ulltoa(u, buf, sizeof(buf), base);
	return (write(fd, s.data, s.len));
}

int	write_hex(int fd, t_format *f, va_list ap)
{
	char			buf[64];
	unsigned int	x;
	t_str			s;

	(void)f;
	x = va_arg(ap, unsigned int);
	s = ft_ulltoa(x, buf, sizeof(buf), 16);
	return (write(fd, s.data, s.len));
}
