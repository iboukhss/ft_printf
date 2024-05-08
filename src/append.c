/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:41:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 03:15:35 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "libft.h"

void	append(t_buffer *b, const void *src, size_t n)
{
	const char	*s;

	s = src;
	while (n)
	{
		if (b->error)
			return ;
		while (n && b->len < b->cap)
		{
			b->data[b->len++] = *s++;
			++b->cnt;
			--n;
		}
		if (n)
		{
			flush(b);
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

void	append_ptr(t_buffer *b, t_format *f, va_list ap)
{
	char		tmp[64];
	size_t		len;
	uintptr_t	p;

	(void)f;
	p = va_arg(ap, uintptr_t);
	if (!p)
		return (append(b, "(nil)", 5));
	len = ft_u64toa_base(p, tmp, sizeof(tmp), HEX);
	append(b, "0x", 2);
	append(b, tmp, len);
}
