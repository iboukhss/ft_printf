/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:49:17 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/05 23:27:57 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

const char	*parse_flags(const char **fmt, t_format *f)
{
	const char	*ptr;

	ptr = *fmt;
	while (*ptr)
	{
		if (*ptr == '#')
			f->alt_form = *ptr;
		else if (*ptr == '0')
			f->zero_pad = *ptr;
		else if (*ptr == '-')
			f->left_adj = *ptr;
		else if (*ptr == ' ')
			f->blank_sign = *ptr;
		else if (*ptr == '+')
			f->plus_sign = *ptr;
		else
			break ;
		++ptr;
	}
	return (ptr);
}

const char	*parse_width(const char **fmt, t_format *f)
{
	const char	*ptr;

	ptr = *fmt;
	while (ft_isdigit(*ptr))
	{
		f->width = f->width * 10 + (*ptr - '0');
		++ptr;
	}
	if (*ptr == '.')
	{
		f->precision = 0;
		if (*++ptr == '\0' || *ptr == '-')
		{
			f->invalid = 1;
			return (ptr);
		}
		while (ft_isdigit(*ptr))
		{
			f->precision = f->precision * 10 + (*ptr - '0');
			++ptr;
		}
	}
	return (ptr);
}
