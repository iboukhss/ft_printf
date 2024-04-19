/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/18 23:40:13 by iboukhss         ###   ########.fr       */
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

size_t	ft_strlen(const char *s);
int		ft_putchar_fd(int fd, int c);
int		ft_putstr_fd(int fd, const char *s);
char	*ft_i32toa(char *dst, int32_t val, size_t size);
char	*ft_u64toa(char *dst, uint64_t val, size_t size);

#endif
