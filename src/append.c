/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:41:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 23:06:19 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "libft.h"

void	append(t_buffer *buf, const void *src, size_t n)
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
			flush(buf);
		}
	}
}

void	fill(t_buffer *buf, int c, size_t n)
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
			flush(buf);
		}
	}
}

void	flush(t_buffer *buf)
{
	buf->error |= (write(buf->fd, buf->data, buf->len) == -1);
	if (buf->error)
		return ;
	buf->len = 0;
}

void	append_char(t_buffer *buf, t_format *f, va_list ap)
{
	int	c;

	if (f->specifier == '%')
		return (append(buf, "%", 1));
	c = va_arg(ap, int);
	append(buf, &c, 1);
}

void	append_str(t_buffer *buf, t_format *f, va_list ap)
{
	char	*s;
	size_t	i;

	(void)f;
	s = va_arg(ap, char *);
	if (!s)
		return (append(buf, "(null)", 6));
	i = ft_strlen(s);
	append(buf, s, i);
}
