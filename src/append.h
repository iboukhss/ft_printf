/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:43:05 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/22 13:19:58 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPEND_H
# define APPEND_H

# include "ft_printf.h"

void	get_padding(t_print *p, t_format *f);
void	append_pri(t_buffer *buf, t_print *pri);
void	append_char(t_buffer *buf, t_format *f, va_list ap);
void	append_str(t_buffer *buf, t_format *f, va_list ap);
void	append_ptr(t_buffer *buf, t_format *f, va_list ap);
void	append_int(t_buffer *buf, t_format *f, va_list ap);
void	append_uint(t_buffer *buf, t_format *f, va_list ap);
void	append_hex(t_buffer *buf, t_format *f, va_list ap);

#endif
