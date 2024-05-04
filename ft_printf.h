/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 04:26:00 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE	1024

typedef struct s_str
{
	unsigned char	*data;
	size_t			len;
}	t_str;

typedef struct s_format
{
	int	alt_form;
	int	zero_pad;
	int	left_adj;
	int	blank_sign;
	int	plus_sign;
	int	width;
	int	precision;
	int	specifier;
}	t_format;

typedef int (*t_funptr)(int, t_format *, va_list);

int	ft_printf(const char *fmt, ...);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);

size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
void	*ft_memset(void *ptr, int c, size_t n);
t_str	ft_itoa(int val, char *buf, size_t size);
t_str	ft_ulltoa(unsigned long long val, char *buf, size_t size, int base);

int	write_chr(int fd, t_format *f, va_list ap);
int	write_cstr(int fd, t_format *f, va_list ap);
int	write_ptr(int fd, t_format *f, va_list ap);
int	write_int(int fd, t_format *f, va_list ap);
int	write_uint_base(int fd, t_format *f, va_list ap);
int	write_hex(int fd, t_format *f, va_list ap);

#endif
