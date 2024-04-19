/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:45:27 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/19 19:21:39 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	count_digits_hex(uint64_t n)
{
	size_t	r;

	r = 1;
	while (n >> 4)
	{
		n >>= 4;
		++r;
	}
	return (r);
}

int	fmt_u(int fd, va_list ap)
{
	unsigned int	u;
	char			buf[21];
	char			*s;

	u = va_arg(ap, unsigned int);
	s = ft_u64toa(buf, u, sizeof(buf));
	return (ft_putstr_fd(fd, s));
}

int	fmt_x(int fd, va_list ap)
{
	static const char	base16[16] = "0123456789abcdef";
	unsigned int		x;
	char				buf[17];
	size_t				len;

	x = va_arg(ap, unsigned int);
	len = count_digits_hex(x);
	buf[len] = '\0';
	while (len--)
	{
		buf[len] = base16[x & 15];
		x >>= 4;
	}
	return (ft_putstr_fd(fd, buf));
}

int	fmt_xx(int fd, va_list ap)
{
	static const char	base16[16] = "0123456789ABCDEF";
	unsigned int		x;
	char				buf[17];
	size_t				len;

	x = va_arg(ap, unsigned int);
	len = count_digits_hex(x);
	buf[len] = '\0';
	while (len--)
	{
		buf[len] = base16[x & 15];
		x >>= 4;
	}
	return (ft_putstr_fd(fd, buf));
}

int	fmt_p(int fd, va_list ap)
{
	static const char	base16[16] = "0123456789abcdef";
	uintptr_t			p;
	char				buf[19];
	size_t				len;

	p = va_arg(ap, uintptr_t);
	if (!p)
		return (ft_putstr_fd(fd, "(nil)"));
	len = count_digits_hex(p) + 2;
	buf[len] = '\0';
	while (len--)
	{
		buf[len] = base16[p & 15];
		p >>= 4;
	}
	buf[0] = '0';
	buf[1] = 'x';
	return (ft_putstr_fd(fd, buf));
}
