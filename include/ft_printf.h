/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/16 00:52:58 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

typedef int	(*t_fun_ptr)(int, va_list);

int		ft_printf(const char *fmt, ...);
int		ft_vdprintf(int fd, const char *fmt, va_list ap);

int		ft_putchar_fd(int fd, int c);
int		ft_putstr_fd(int fd, const char *s);
size_t	ft_strlen(const char *s);
char	*ft_i32toa(char *dst, size_t size, int32_t val);

/* Print format handlers */
int	fmt_c(int fd, va_list ap);
int	fmt_s(int fd, va_list ap);
int	fmt_i(int fd, va_list ap);
int	fmt_err(int fd, va_list ap);
int	fmt_pc(int fd, va_list ap);

#endif
