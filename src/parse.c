/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:49:17 by iboukhss          #+#    #+#             */
/*   Updated: 2024/05/11 18:23:30 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

void	parse_flags(const char **fmt, t_format *f)
{
	if (f->invalid)
		return ;
	while (**fmt)
	{
		if (**fmt == '#')
			f->alt_form = true;
		else if (**fmt == '0')
			f->zero_pad = true;
		else if (**fmt == '-')
			f->left_adj = true;
		else if (**fmt == ' ')
			f->hide_pos = true;
		else if (**fmt == '+')
			f->show_pos = true;
		else
			break ;
		(*fmt)++;
	}
}

void	parse_width(const char **fmt, t_format *f)
{
	if (f->invalid)
		return ;
	while (ft_isdigit(**fmt))
	{
		f->width = f->width * 10 + (**fmt - '0');
		(*fmt)++;
	}
}

void	parse_precision(const char **fmt, t_format *f)
{
	if (f->invalid)
		return ;
	if (**fmt == '.')
	{
		(*fmt)++;
		f->invalid |= (**fmt == '\0' || **fmt == '-');
		if (f->invalid)
			return ;
		f->precision = 0;
		while (ft_isdigit(**fmt))
		{
			f->precision = f->precision * 10 + (**fmt - '0');
			(*fmt)++;
		}
	}
}

void	check_format(t_format *f)
{
	unsigned char	s;

	if (f->invalid)
		return ;
	s = f->specifier;
	if (f->alt_form)
	{
		f->invalid |= (s != 'x' && s != 'X');
	}
	if (f->zero_pad)
	{
		f->invalid |= (s == '%' || s == 'c' || s == 's' || s == 'p');
	}
	if (f->hide_pos || f->show_pos)
	{
		f->invalid |= (s != 'd' && s != 'i');
	}
	if (f->precision >= 0)
	{
		f->invalid |= (s == '%' || s == 'c' || s == 'p');
	}
}
