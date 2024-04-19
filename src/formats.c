/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:44:31 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/18 23:23:32 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	fmt_c(int fd, va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	return (ft_putchar_fd(fd, c));
}

int	fmt_s(int fd, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	return (ft_putstr_fd(fd, s));
}

int	fmt_i(int fd, va_list ap)
{
	int32_t	i;
	char	buf[12];
	char	*s;

	i = va_arg(ap, int32_t);
	s = ft_i32toa(buf, i, sizeof(buf));
	return (ft_putstr_fd(fd, s));
}

int	fmt_err(int fd, va_list ap)
{
	(void)fd;
	(void)ap;
	return (-1);
}

int	fmt_pc(int fd, va_list ap)
{
	(void)ap;
	return (ft_putchar_fd(fd, '%'));
}
