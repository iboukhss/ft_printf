/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:41:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/04 22:26:26 by iboukhss         ###   ########.fr       */
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

void	append_int(t_buffer *b, t_format *f, va_list ap)
{
	char	tmp[64];
	size_t	i;
	int		n;
	int		neg;

	(void)f;
	i = sizeof(tmp);
	neg = 0;
	n = va_arg(ap, int);
	if (n < 0)
		neg = 1;
	else
		n = -n;
	while (i)
	{
		tmp[--i] = '0' - (n % 10);
		n /= 10;
		if (!n)
			break ;
	}
	if (neg)
		tmp[--i] = '-';
	append(b, tmp + i, sizeof(tmp) - i);
}
