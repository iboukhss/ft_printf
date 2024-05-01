/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/01 23:49:44 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <string.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_format	f;
	size_t		cnt = 0;

	while (*fmt)
	{
		// specifier
		if (*fmt == '%')
		{
			// initialize format
			memset(&f, 0, sizeof(f));
			f.precision = -1;

			// skip over
			++fmt;

			if (*fmt == '\0')
				return (-1);

			// parse flags
			while (1)
			{
				if (*fmt == '#')
					f.alt_form = *fmt;
				else if (*fmt == '0')
					f.zero_pad = *fmt;
				else if (*fmt == '-')
					f.left_adj = *fmt;
				else if (*fmt == ' ')
					f.blank_sign = *fmt;
				else if (*fmt == '+')
					f.plus_sign = *fmt;
				else
					break ;
				++fmt;
			}

			// parse width
			while (ft_isdigit(*fmt))
			{
				f.width = f.width * 10 + (*fmt - '0');
				++fmt;
			}

			// parse precision
			if (*fmt == '.')
			{
				// skip over
				++fmt;

				if (*fmt == '\0' || *fmt == '-')
					return (-1);

				while (ft_isdigit(*fmt))
				{
					f.precision = f.precision * 10 + (*fmt - '0');
					++fmt;
				}
			}

			// %cspdibouxX
			if (*fmt == '%')
			{
				cnt += write(fd, fmt, 1);
			}
			else if (*fmt == 'c')
			{
				int c = va_arg(ap, int);

				cnt += write(fd, &c, 1);
			}
			else if (*fmt == 's')
			{
				char *s = va_arg(ap, char *);

				if (!s)
					cnt += write(fd, "(null)", 6);
				else
					cnt += write(fd, s, strlen(s));
			}
			else if (*fmt == 'p')
			{
				uintptr_t p = va_arg(ap, uintptr_t);

				if (!p)
					cnt += write(fd, "(nil)", 5);
				else
				{
					unsigned char buf[64];
					unsigned char *end = buf + sizeof(buf);
					unsigned char *beg = end;

					cnt += write(fd, "0x", 2);
					while (1)
					{
						*--beg = "0123456789abcdef"[p % 16];
						p /= 16;
						if (!p)
							break ;
					}
					cnt += write(fd, beg, end - beg);
				}
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				int i = va_arg(ap, int);

				unsigned char buf[64];
				unsigned char *end = buf + sizeof(buf);
				unsigned char *beg = end;

				if (i < 0)
					cnt += write(fd, "-", 1);
				else
					i = -i;
				while (1)
				{
					*--beg = '0' - (i % 10);
					i /= 10;
					if (!i)
						break ;
				}
				cnt += write(fd, beg, end - beg);
			}
			// everything below should be very similar
			else if (*fmt == 'b')
			{
				// TODO
			}
			else if (*fmt == 'o')
			{
				// TODO
			}
			else if (*fmt == 'u')
			{
				unsigned int u = va_arg(ap, unsigned int);

				unsigned char buf[64];
				unsigned char *end = buf + sizeof(buf);
				unsigned char *beg = end;

				while (1)
				{
					*--beg = '0' + (u % 10);
					u /= 10;
					if (!u)
						break ;
				}
				cnt += write(fd, beg, end - beg);
			}
			else if (*fmt == 'x')
			{
				unsigned int x = va_arg(ap, unsigned int);

				unsigned char buf[64];
				unsigned char *end = buf + sizeof(buf);
				unsigned char *beg = end;

				while (1)
				{
					*--beg = "0123456789abcdef"[x % 16];
					x /= 16;
					if (!x)
						break ;
				}
				cnt += write(fd, beg, end - beg);
			}
			else if (*fmt == 'X')
			{
				unsigned int x = va_arg(ap, unsigned int);

				unsigned char buf[64];
				unsigned char *end = buf + sizeof(buf);
				unsigned char *beg = end;

				while (1)
				{
					*--beg = "0123456789ABCDEF"[x % 16];
					x /= 16;
					if (!x)
						break ;
				}
				cnt += write(fd, beg, end - beg);
			}
			// invalid specifier
			else
				return (-1);
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
