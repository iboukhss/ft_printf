/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:30:56 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/22 21:38:01 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>

ssize_t	ft_strscpy(char *dst, const char *src, size_t size)
{
	size_t	cnt;

	if (!size)
		return (-E2BIG);
	cnt = 0;
	while (*src && cnt < size - 1)
	{
		*dst++ = *src++;
		++cnt;
	}
	*dst = '\0';
	if (*src)
		return (-E2BIG);
	return (cnt);
}
