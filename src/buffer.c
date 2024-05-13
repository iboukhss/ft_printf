/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:01:16 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/13 06:11:08 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

void	buf_cpy(t_buffer *buf, const void *src, size_t n)
{
	const char	*s;

	s = src;
	while (n)
	{
		if (buf->error)
			return ;
		while (n && buf->len < buf->cap)
		{
			buf->data[buf->len++] = *s++;
			++buf->cnt;
			--n;
		}
		if (n)
		{
			buf_flush(buf);
		}
	}
}

void	buf_set(t_buffer *buf, int c, size_t n)
{
	while (n)
	{
		if (buf->error)
			return ;
		while (n && buf->len < buf->cap)
		{
			buf->data[buf->len++] = c;
			++buf->cnt;
			--n;
		}
		if (n)
		{
			buf_flush(buf);
		}
	}
}

void	buf_flush(t_buffer *buf)
{
	if (!buf->error)
	{
		buf->error |= (write(buf->fd, buf->data, buf->len) == -1);
		buf->len = 0;
	}
}
