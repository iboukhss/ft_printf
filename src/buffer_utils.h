/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:09:38 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/29 04:59:25 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_UTILS_H
# define BUFFER_UTILS_H

# include "ft_printf.h"

void	buffer_memcpy(t_buffer *buf, const void *src, size_t n);
void	append_byte(t_buffer *buf, va_list ap, t_info *inf);
void	append_str(t_buffer *buf, va_list ap, t_info *inf);
void	append_int(t_buffer *buf, va_list ap, t_info *inf);
void	append_uint(t_buffer *buf, va_list ap, t_info *inf);
void	append_hex(t_buffer *buf, va_list ap, t_info *inf);
void	append_ptr(t_buffer *buf, va_list ap, t_info *inf);

#endif
