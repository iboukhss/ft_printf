/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:43:05 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 19:45:06 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPEND_H
# define APPEND_H

# include "ft_printf.h"
# include <stdint.h>

void	append(t_buffer *buf, const void *src, size_t n);
void	append_byte(t_buffer *b, t_format *f, va_list ap);
void	append_str(t_buffer *b, t_format *f, va_list ap);
void	append_ptr(t_buffer *b, t_format *f, va_list ap);
void	append_int(t_buffer *b, t_format *f, va_list ap);
void	append_uint(t_buffer *b, t_format *f, va_list ap);
void	append_hex(t_buffer *b, t_format *f, va_list ap);
void	append_oct(t_buffer *b, t_format *f, va_list ap);
void	append_bin(t_buffer *b, t_format *f, va_list ap);

#endif
