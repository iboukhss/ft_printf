/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 10:27:37 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

# define BUFSIZ 1024

typedef struct s_buffer
{
	int		fd;
	char	data[BUFSIZ];
	size_t	cap;
	size_t	len;
	size_t	cnt;
	int		error;
}	t_buffer;

typedef struct s_format
{
	bool	alt_form;
	bool	zero_pad;
	bool	left_adj;
	bool	hide_pos;
	bool	show_pos;
	int		width;
	int		precision;
	uint8_t	specifier;
	bool	invalid;
}	t_format;

typedef void	(*t_funptr)(t_buffer *, t_format *, va_list);

int	ft_printf(const char *fmt, ...);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);

#endif
