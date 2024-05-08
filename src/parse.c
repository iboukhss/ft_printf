/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:49:17 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/08 02:16:27 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

const char	*parse_flags(const char **fmt, t_format *f)
{
	const char	*s;

	if (f->invalid)
		return (*fmt);
	s = *fmt;
	while (*s)
	{
		if (*s == '#')
			f->alt_form = true;
		else if (*s == '0')
			f->zero_pad = true;
		else if (*s == '-')
			f->left_adj = true;
		else if (*s == ' ')
			f->blank_sign = true;
		else if (*s == '+')
			f->plus_sign = true;
		else
			break ;
		++s;
	}
	return (s);
}

const char	*parse_width(const char **fmt, t_format *f)
{
	const char	*s;

	if (f->invalid)
		return (*fmt);
	s = *fmt;
	while (ft_isdigit(*s))
	{
		f->width = f->width * 10 + (*s - '0');
		++s;
	}
	return (s);
}

const char	*parse_precision(const char **fmt, t_format *f)
{
	const char	*s;

	if (f->invalid)
		return (*fmt);
	s = *fmt;
	if (*s == '.')
	{
		++s;
		f->invalid |= (*s == '\0' || *s == '-');
		if (f->invalid)
			return (*fmt);
		f->precision = 0;
		while (ft_isdigit(*s))
		{
			f->precision = f->precision * 10 + (*s - '0');
			++s;
		}
	}
	return (s);
}
