/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:39 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/05 20:32:14 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "append.h"
#include "libft.h"

void	append_int(t_buffer *b, t_format *f, va_list ap)
{
	char	tmp[64];
	size_t	i;
	int		n;
	int		neg;

	i = sizeof(tmp);
	n = va_arg(ap, int);
	neg = 0;
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
		append(b, "-", 1);
	else if (f->plus_sign)
		append(b, "+", 1);
	else if (f->blank_sign)
		append(b, " ", 1);
	append(b, tmp + i, sizeof(tmp) - i);
}

void	append_uint(t_buffer *b, t_format *f, va_list ap)
{
	char			tmp[64];
	size_t			i;
	unsigned int	u;

	(void)f;
	u = va_arg(ap, unsigned int);
	i = ft_u64toa(u, tmp, sizeof(tmp));
	if (f->plus_sign)
		append(b, "+", 1);
	else if (f->blank_sign)
		append(b, " ", 1);
	append(b, tmp, i);
}

void	append_hex(t_buffer *b, t_format *f, va_list ap)
{
	char			tmp[64];
	size_t			i;
	unsigned int	x;
	int				lower;

	x = va_arg(ap, unsigned int);
	i = sizeof(tmp);
	lower = (f->specifier & 0x20);
	while (i)
	{
		tmp[--i] = "0123456789ABCDEF"[x & 15] | lower;
		x >>= 4;
		if (!x)
			break ;
	}
	if (f->alt_form && lower)
		append(b, "0x", 2);
	else if (f->alt_form)
		append(b, "0X", 2);
	append(b, tmp + i, sizeof(tmp) - i);
}
