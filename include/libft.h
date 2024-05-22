/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:22:29 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/22 21:35:53 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
size_t	ft_strnlen(const char *str, size_t n);
ssize_t	ft_strscpy(char *dst, const char *src, size_t size);

int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_toupper(int c);

char	*ft_strupr(char *str);

void	*ft_memset(void *dst, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

int		ft_u64toa(char *buf, uint64_t val, size_t size);
int		ft_u64toa_hex(char *buf, uint64_t val, size_t size);
int		ft_i64toa_abs(char *buf, int64_t val, size_t size);

#endif
