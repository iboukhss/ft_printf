/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:24:32 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/13 18:50:20 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/ft_printf.h"

int	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;
	ssize_t	wr;

	len = ft_strlen(s);
	wr = write(fd, s, len);
	if (wr == -1)
		return (-1);
	return (len);
}
