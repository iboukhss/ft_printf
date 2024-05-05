/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/06 01:21:57 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define BUFSIZ 1024

typedef struct s_buffer
{
	int		fd;
	char	data[BUFSIZ];
	size_t	len;
	size_t	cnt;
	int		error;
}	t_buffer;

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
	int	invalid;
}	t_format;

typedef void	(*t_funptr)(t_buffer *, t_format *, va_list);

int	ft_printf(const char *fmt, ...);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);

#endif
