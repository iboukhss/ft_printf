/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/15 11:05:14 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

typedef int	(*t_fun_ptr)(int, va_list);

int		ft_printf(const char *fmt, ...);
int		ft_vdprintf(int fd, const char *fmt, va_list ap);

int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(const char *s, int fd);
size_t	ft_strlen(const char *s);

/* Print format handlers */
int	fmt_c(int fd, va_list ap);
int	fmt_s(int fd, va_list ap);
int	fmt_err(int fd, va_list ap);

#endif
