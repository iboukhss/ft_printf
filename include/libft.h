/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:22:29 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 17:28:01 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>

# define BIN	0x62
# define OCT	0x6F
# define HEX	0x78
# define UBIN	0x42
# define UHEX	0x58

size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_u64toa(uint64_t val, char *buf, size_t size);
int		ft_u64toa_base(uint64_t val, char *buf, size_t size, int base);
int		ft_i64toa(int64_t val, char *buf, size_t size);

void	*ft_memset(void *ptr, int c, size_t n);

#endif
