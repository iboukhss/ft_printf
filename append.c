/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:41:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/05 20:32:55 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "libft.h"

void	flush(t_buffer *b)
{
	write(b->fd, b->data, b->len);
	b->len = 0;
	b->full = 0;
}

void	append(t_buffer *b, const void *src, size_t n)
{
	const char	*s;
	size_t		avail;

	s = src;
	while (n)
	{
		avail = b->cap - b->len;
		b->full |= n > avail;
		while (n && b->len < b->cap)
		{
			b->data[b->len] = *s;
			++b->len;
			++b->cnt;
			++s;
			--n;
		}
		if (b->full)
			flush(b);
	}
}

void	append_byte(t_buffer *b, t_format *f, va_list ap)
{
	int	c;

	if (f->specifier == '%')
	{
		append(b, "%", 1);
		return ;
	}
	c = va_arg(ap, int);
	append(b, &c, 1);
}

void	append_str(t_buffer *b, t_format *f, va_list ap)
{
	char	*s;
	size_t	i;

	(void)f;
	s = va_arg(ap, char *);
	if (!s)
	{
		append(b, "(null)", 6);
		return ;
	}
	i = ft_strlen(s);
	append(b, s, i);
}

void	append_ptr(t_buffer *b, t_format *f, va_list ap)
{
	char		tmp[64];
	size_t		i;
	uintptr_t	p;

	(void)f;
	i = sizeof(tmp);
	p = va_arg(ap, uintptr_t);
	if (!p)
	{
		append(b, "(nil)", 5);
		return ;
	}
	while (p)
	{
		tmp[--i] = "0123456789abcdef"[p & 15];
		p >>= 4;
	}
	append(b, "0x", 2);
	append(b, tmp + i, sizeof(tmp) - i);
}
