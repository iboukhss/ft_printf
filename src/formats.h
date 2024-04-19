/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:39:21 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/19 01:56:46 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
# define FORMATS_H

# include <stdarg.h>

/* Print format handlers */
int	fmt_c(int fd, va_list ap);
int	fmt_s(int fd, va_list ap);
int	fmt_i(int fd, va_list ap);
int	fmt_err(int fd, va_list ap);
int	fmt_pc(int fd, va_list ap);
int	fmt_u(int fd, va_list ap);
int	fmt_x(int fd, va_list ap);
int	fmt_xx(int fd, va_list ap);
int	fmt_p(int fd, va_list ap);

#endif
