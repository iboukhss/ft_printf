/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/15 11:03:41 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* Initialize lookup table for the entire char range */
t_fun_ptr	*init_table(void)
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
	lut['p'] = &fmt_err;
	lut['d'] = &fmt_err;
	lut['i'] = &fmt_err;
	lut['u'] = &fmt_err;
	lut['x'] = &fmt_err;
	lut['X'] = &fmt_err;
	lut['%'] = &fmt_err;
	return (lut);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_fun_ptr	*lut;
	int			ret;
	int			wr;

	lut = init_table();
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			wr = lut[(unsigned char)*fmt](fd, ap);
			if (wr == -1)
				return (-1);
		}
		else
		{
			wr = ft_putchar_fd(*fmt, fd);
			if (wr == -1)
				return (-1);
			ret += wr;
		}
		++fmt;
	}
	return (ret);
}
