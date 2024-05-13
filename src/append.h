/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:43:05 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/13 07:02:42 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPEND_H
# define APPEND_H

# include "ft_printf.h"

int		append_prefix(t_buffer *buf, t_format *f, int len, const char *prefix);
void	append_char(t_buffer *b, t_format *f, va_list ap);
void	append_str(t_buffer *b, t_format *f, va_list ap);
void	append_ptr(t_buffer *b, t_format *f, va_list ap);
void	append_int(t_buffer *b, t_format *f, va_list ap);
void	append_uint(t_buffer *b, t_format *f, va_list ap);
void	append_hex(t_buffer *b, t_format *f, va_list ap);

#endif
