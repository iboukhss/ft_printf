/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:43:05 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 23:03:32 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPEND_H
# define APPEND_H

# include "ft_printf.h"

void	flush(t_buffer *buf);
void	append(t_buffer *buf, const void *src, size_t n);
void	fill(t_buffer *buf, int c, size_t n);

void	append_char(t_buffer *b, t_format *f, va_list ap);
void	append_str(t_buffer *b, t_format *f, va_list ap);
void	append_ptr(t_buffer *b, t_format *f, va_list ap);
void	append_int(t_buffer *b, t_format *f, va_list ap);

void	append_uint(t_buffer *b, t_format *f, va_list ap);
void	append_hex(t_buffer *b, t_format *f, va_list ap);

#endif
