/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:24:32 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/19 19:20:09 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr_fd(int fd, const char *s)
{
	size_t	len;
	ssize_t	wrc;

	if (!s)
		return (ft_putstr_fd(fd, "(null)"));
	len = ft_strlen(s);
	wrc = write(fd, s, len);
	if (wrc == -1)
		return (-1);
	return (wrc);
}
