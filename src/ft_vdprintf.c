/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/19 19:12:49 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "formats.h"

static t_fun_ptr	*init_table(void)
{
	static t_fun_ptr	lut[256];
	int					i;

	i = 0;
	while (i < 256)
	{
		lut[i] = &fmt_err;
		++i;
	}
	lut['c'] = &fmt_c;
	lut['s'] = &fmt_s;
	lut['p'] = &fmt_p;
	lut['d'] = &fmt_i;
	lut['i'] = &fmt_i;
	lut['u'] = &fmt_u;
	lut['x'] = &fmt_x;
	lut['X'] = &fmt_xx;
	lut['%'] = &fmt_pc;
	return (lut);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_fun_ptr	*lut;
	size_t		ret;
	ssize_t		wrc;

	ret = 0;
	lut = init_table();
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			wrc = lut[(unsigned char)*fmt](fd, ap);
			if (wrc == -1)
				return (-1);
		}
		else
		{
			wrc = ft_putchar_fd(fd, *fmt);
			if (wrc == -1)
				return (-1);
		}
		ret += wrc;
		++fmt;
	}
	return (ret);
}
