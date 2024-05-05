/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:22:29 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/05 17:27:32 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>

size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_u64toa(uint64_t val, char *buf, size_t size);

void	*ft_memset(void *ptr, int c, size_t n);

#endif
