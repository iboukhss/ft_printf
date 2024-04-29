/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:07:53 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/29 06:03:49 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void	buffer_memcpy(t_buffer *buf, const void *src, size_t n)
{
	memcpy(buf->data + buf->len, src, n);
	buf->len += n;
}

void	append_byte(t_buffer *buf, va_list ap, t_info *inf)
{
	int	byte;

	(void)inf;
	byte = va_arg(ap, int);
	buffer_memcpy(buf, &byte, 1);
}

void	append_str(t_buffer *buf, va_list ap, t_info *inf)
{
	char	*str;
	size_t	len;

	(void)inf;
	str = va_arg(ap, char *);
	if (!str)
	{
		buffer_memcpy(buf, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	buffer_memcpy(buf, str, len);
}

void	append_int(t_buffer *buf, va_list ap, t_info *inf)
{
	unsigned char	tmp[32];
	unsigned char	*str;
	int				val;

	(void)inf;
	val = va_arg(ap, int);
	str = ft_itoa(tmp, val, sizeof(tmp));
	buffer_memcpy(buf, str, tmp + sizeof(tmp) - str - 1);
}

void	append_uint(t_buffer *buf, va_list ap, t_info *inf)
{
	unsigned char	tmp[32];
	unsigned char	*str;
	unsigned int	val;

	(void)inf;
	val = va_arg(ap, unsigned int);
	str = ft_utoa(tmp, val, sizeof(tmp));
	buffer_memcpy(buf, str, tmp + sizeof(tmp) - str - 1);
}

void	append_hex(t_buffer *buf, va_list ap, t_info *inf)
{
	unsigned char	tmp[32];
	size_t			size;
	unsigned int	hex;

	hex = va_arg(ap, unsigned int);
	size = sizeof(tmp);
	while (size)
	{
		tmp[--size] = "0123456789ABCDEF"[hex & 15] | inf->lower;
		hex >>= 4;
		if (!hex)
			break ;
	}
	buffer_memcpy(buf, tmp + size, sizeof(tmp) - size);
}

void	append_ptr(t_buffer *buf, va_list ap, t_info *inf)
{
	void	*ptr;
	va_list	ap_copy;

	(void)inf;
	va_copy(ap_copy, ap);
	ptr = va_arg(ap, void *);
	if (!ptr)
	{
		buffer_memcpy(buf, "(nil)", 5);
		return ;
	}
	buffer_memcpy(buf, "0x", 2);
	append_hex(buf, ap_copy, inf);
	va_end(ap_copy);
}
