/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:51:00 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/05 23:17:15 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "ft_printf.h"

const char	*parse_flags(const char **fmt, t_format *f);
const char	*parse_width(const char **fmt, t_format *f);

#endif
