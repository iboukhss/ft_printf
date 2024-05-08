/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:51:00 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 14:41:08 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "ft_printf.h"

void	parse_flags(const char **fmt, t_format *f);
void	parse_width(const char **fmt, t_format *f);
void	parse_precision(const char **fmt, t_format *f);

#endif
