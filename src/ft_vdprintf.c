/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:48:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/04/29 05:58:36 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "buffer_utils.h"

#include <string.h>
#include <ctype.h>
#include <errno.h>

static const char	*handle_literal(const char *fmt, t_buffer *buf, t_info *inf)
{
	if (*fmt == '%')
		inf->state = FLAGS;
	else
		buffer_memcpy(buf, fmt, 1);
	return (fmt + 1);
}

static const char	*handle_flags(const char *fmt, t_info *inf)
{
	int	i;

	i = 0;
	while (strchr("#0- +", fmt[i]))
	{
		if (fmt[i] == '#')
			inf->alt_form = true;
		else if (fmt[i] == '-')
			inf->left_align = true;
		else if (fmt[i] == '0' && !inf->left_align)
			inf->zero_pad = true;
		else if (fmt[i] == '+')
			inf->pos_sign = '+';
		else if (fmt[i] == ' ' && inf->pos_sign != '+')
			inf->pos_sign = ' ';
		++i;
	}
	inf->state = WIDTH;
	return (fmt + i);
}

static const char	*handle_width(const char *fmt, t_info *inf)
{
	int	i;

	i = 0;
	while (fmt[i] && isdigit(fmt[i]))
	{
		inf->max_width = inf->max_width * 10 + fmt[i] - '0';
		++i;
	}
	if (fmt[i] == '.')
		++i;
	while (fmt[i] && isdigit(fmt[i]))
	{
		inf->min_width = inf->min_width * 10 + fmt[i] - '0';
		++i;
	}
	inf->state = SPECIFIER;
	return (fmt + i);
}

static const char	*handle_specifier(const char *fmt, t_buffer *buf, t_info *inf, va_list ap)
{
	if (islower(*fmt))
		inf->lower = 32;
	if (*fmt == 'c')
		append_byte(buf, ap, inf);
	else if (*fmt == 's')
		append_str(buf, ap, inf);
	else if (*fmt == 'p')
		append_ptr(buf, ap, inf);
	else if (*fmt == 'd' || *fmt == 'i')
		append_int(buf, ap, inf);
	else if (*fmt == 'u')
		append_uint(buf, ap, inf);
	else if (*fmt == 'x' || *fmt == 'X')
		append_hex(buf, ap, inf);
	else if (*fmt == '%')
		buffer_memcpy(buf, fmt, 1);
	else
	{
		inf->state = INVALID;
		return (fmt);
	}
	inf->state = LITERAL;
	return (fmt + 1);
}

static void	reset_info(t_info *inf)
{
	inf->alt_form = 0;
	inf->zero_pad = 0;
	inf->left_align = 0;
	inf->pos_sign = 0;
	inf->min_width = 0;
	inf->max_width = 0;
	inf->lower = 0;
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_info		inf = { 0 };
	t_buffer	buf = { 0 };

	while (*fmt && inf.state != INVALID)
	{
		if (inf.state == LITERAL)
		{
			reset_info(&inf);
			fmt = handle_literal(fmt, &buf, &inf);
		}
		else if (inf.state == FLAGS)
			fmt = handle_flags(fmt, &inf);
		else if (inf.state == WIDTH)
			fmt = handle_width(fmt, &inf);
		else if (inf.state == SPECIFIER)
			fmt = handle_specifier(fmt, &buf, &inf, ap);
	}
	if (inf.state != LITERAL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (write(fd, buf.data, buf.len) == -1)
		return (-1);
	return (buf.len);
}
