/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/22 14:09:18 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

/* A buffer that can flush itself when full */
typedef struct s_buffer
{
	int		fd;
	char	data[BUFFER_SIZE];
	size_t	cap;
	size_t	len;
	size_t	cnt;
	bool	error;
}	t_buffer;

/* A struct to record all flags passed to printf */
typedef struct s_format
{
	bool			alt_form;
	bool			zero_pad;
	bool			left_adj;
	bool			hide_pos;
	bool			show_pos;
	int				width;
	int				precision;
	unsigned char	specifier;
	bool			invalid;
}	t_format;

/* Function pointer definition for specifier handling functions */
typedef void	(*t_funptr)(t_buffer *, t_format *, va_list);

/* A struct to hold padding offsets before printing.
 *
 * [lpad] [prefix] [zpad] [string] [rpad]
 *
 * lpad: left padding with spaces, enabled by the width field
 * pfx : prefix, can be any of the following: [+|-| |0x|0X|0b|0B]
 * plen: prefix length
 * zpad: zero padding, enabled by the precision field or the '0' flag
 * str : string without any prefix, width or precision padding
 * slen: string length
 * rpad: right padding with spaces, enabled by the '-' flag
 */
typedef struct s_print
{
	int		lpad;
	char	*pfx;
	int		plen;
	int		zpad;
	char	*str;
	int		slen;
	int		rpad;
}	t_print;

int	ft_printf(const char *fmt, ...);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);

#endif
