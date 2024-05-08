/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:35:02 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 23:02:40 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*g_tab[256] = {
['b'] = "01",
['B'] = "01",
['o'] = "01234567",
['x'] = "0123456789abcdef",
['X'] = "0123456789ABCDEF",
};

static size_t	count_digits_base(uint64_t val, int base)
{
	size_t	count;

	count = 0;
	if (val == 0)
		return (1);
	while (val)
	{
		val /= base;
		++count;
	}
	return (count);
}

int	ft_u64toa_base(uint64_t val, char *buf, size_t size, int base)
{
	const char	*digits;
	size_t		len;
	size_t		i;

	if (!g_tab[(unsigned char)base])
		return (-1);
	digits = g_tab[(unsigned char)base];
	base = ft_strlen(digits);
	len = count_digits_base(val, base);
	if (len > size)
		return (-1);
	i = len;
	while (i)
	{
		buf[--i] = digits[val % base];
		val /= base;
	}
	return (len);
}
