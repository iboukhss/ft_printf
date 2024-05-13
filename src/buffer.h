/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:00:46 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/13 06:11:08 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include "ft_printf.h"

void	buf_flush(t_buffer *buf);
void	buf_cpy(t_buffer *buf, const void *src, size_t n);
void	buf_set(t_buffer *buf, int c, size_t n);

#endif
