/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/29 02:29:49 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

# define BUFFER_SIZE 1024

typedef enum e_state
{
	LITERAL,
	FLAGS,
	WIDTH,
	SPECIFIER,
	INVALID
}	t_state;

typedef struct s_info
{
	t_state	state;
	bool	alt_form;
	bool	zero_pad;
	bool	left_align;
	char	pos_sign;
	int		min_width;
	int		max_width;
	int		lower;
}	t_info;

typedef struct s_buffer
{
	char	data[BUFFER_SIZE];
	size_t	len;
}	t_buffer;

int				ft_printf(const char *fmt, ...);
int				ft_vdprintf(int fd, const char *fmt, va_list ap);
size_t			ft_strlen(const char *s);
unsigned char	*ft_itoa(unsigned char *dst, int val, size_t size);
unsigned char	*ft_utoa(unsigned char *dst, unsigned int val, size_t size);

#endif
