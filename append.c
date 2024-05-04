/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:41:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 19:50:07 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"

void	append(t_buffer *b, const void *src, size_t n)
{
	const char	*s;
	size_t		avail;

	avail = b->cap - b->len;
	b->full |= n > avail;
	if (b->full)
		return ;
	s = src;
	while (n--)
	{
		b->data[b->len] = *s;
		++b->len;
		++s;
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

	(void)f;
	s = va_arg(ap, char *);
	if (!s)
	{
		append(b, "(null)", 6);
		return ;
	}
	append(b, s, ft_strlen(s));
}

void	append_ptr(t_buffer *b, t_format *f, va_list ap)
{
	char		tmp[64];
	char		*beg;
	char		*end;
	uintptr_t	p;

	(void)f;
	p = va_arg(ap, uintptr_t);
	if (!p)
	{
		append(b, "(nil)", 5);
		return ;
	}
	end = tmp + sizeof(tmp);
	beg = end;
	while (p)
	{
		*--beg = "0123456789abcdef"[p & 15];
		p >>= 4;
	}
	append(b, "0x", 2);
	append(b, beg, end - beg);
}

void	append_int(t_buffer *b, t_format *f, va_list ap)
{
	char	tmp[64];
	char	*beg;
	char	*end;
	int		i;

	(void)f;
	i = va_arg(ap, int);
	end = tmp + sizeof(tmp);
	beg = end;
	while (i)
	{
		*--beg = '0' + (i % 10);
		i /= 10;
	}
	append(b, beg, end - beg);
}
