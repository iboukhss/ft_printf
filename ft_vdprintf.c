/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/02 02:16:46 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		++s;
	return (s - str);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	*ft_memset(void *ptr, int c, size_t n)
{
	char	*p;

	p = ptr;
	while (n--)
		*p++ = c;
	return (ptr);
}

const char	*parse_format(const char **fmt, t_format *data)
{
	const char	*ptr;

	// initialize data
	ptr = *fmt;
	ft_memset(data, 0, sizeof(*data));
	data->precision = -1;

	// skip over
	++ptr;

	if (*ptr == '\0')
		return (ptr);

	// parse flags
	while (1)
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
	return (ptr);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_format	*f;
	int			cnt;

	cnt = 0;
	while (*fmt)
	{
		// specifier
		if (*fmt == '%')
		{
			fmt = parse_format(&fmt, f);

			if (*fmt == '%')
				cnt += write(fd, fmt, 1);
			else if (*fmt == 'c')
				cnt += write_chr(fd, ap);
			else if (*fmt == 's')
				cnt += write_str(fd, ap);
			else if (*fmt == 'p')
				cnt += write_ptr(fd, ap);
			else if (*fmt == 'd' || *fmt == 'i')
				cnt += write_int(fd, ap);

			// everything below should be very similar
			else if (*fmt == 'b')
				cnt += write_uint_base(fd, ap, 2);
			else if (*fmt == 'o')
				cnt += write_uint_base(fd, ap, 8);
			else if (*fmt == 'u')
				cnt += write_uint_base(fd, ap, 10);
			else if (*fmt == 'x')
				cnt += write_uint_base(fd, ap, 16);
			else if (*fmt == 'X')
				cnt += write_hex(fd, ap);

			else
				return (-1);

			// keep going
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

int	write_chr(int fd, va_list ap)
{
	int c;

	c = va_arg(ap, int);
	return(write(fd, &c, 1));
}

int	write_str(int fd, va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	if (!s)
		return(write(fd, "(null)", 6));
	return(write(fd, s, ft_strlen(s)));
}

int	write_ptr(int fd, va_list ap)
{
	uintptr_t		p;
	unsigned char	buf[64];
	unsigned char	*end;
	unsigned char	*beg;

	p = va_arg(ap, uintptr_t);
	end = buf + sizeof(buf);
	beg = end;
	if (!p)
		return(write(fd, "(nil)", 5));
	while (1)
	{
		*--beg = "0123456789abcdef"[p % 16];
		p /= 16;
		if (!p)
			break ;
	}
	*--beg = 'x';
	*--beg = '0';
	return(write(fd, beg, end - beg));
}

int	write_int(int fd, va_list ap)
{
	int				i;
	unsigned char	buf[64];
	unsigned char	*end;
	unsigned char	*beg;
	int				neg;

	i = va_arg(ap, int);
	end = buf + sizeof(buf);
	beg = end;
	neg = 0;
	if (i < 0)
	{
		write(fd, "-", 1);	// todo: fix incorrect return value here
		neg = 1;
	}
	else
		i = -i;
	while (1)
	{
		*--beg = '0' - (i % 10);
		i /= 10;
		if (!i)
			break ;
	}
	return(write(fd, beg, end - beg) + neg);
}

int	write_uint_base(int fd, va_list ap, int base)
{
	unsigned int	u;
	unsigned char	buf[64];
	unsigned char	*end;
	unsigned char	*beg;

	u = va_arg(ap, unsigned int);
	end = buf + sizeof(buf);
	beg = end;
	while (1)
	{
		*--beg = "0123456789abcdef"[u % base];
		u /= base;
		if (!u)
			break ;
	}
	return(write(fd, beg, end - beg));
}

int	write_hex(int fd, va_list ap)
{
	unsigned int	x;
	unsigned char	buf[64];
	unsigned char	*end;
	unsigned char	*beg;

	x = va_arg(ap, unsigned int);
	end = buf + sizeof(buf);
	beg = end;
	while (1)
	{
		*--beg = "0123456789ABCDEF"[x % 16];
		x /= 16;
		if (!x)
			break ;
	}
	return(write(fd, beg, end - beg));
}
