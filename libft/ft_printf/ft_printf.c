/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:51:10 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/24 16:10:24 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		length += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		length += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		length += ft_printuint(va_arg(args, unsigned int));
	else if (format == '%')
		length += ft_printper();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				length;
	int				index;

	length = 0;
	index = 0;
	if (str == NULL)
		return (0);
	va_start(args, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			length += ft_format(args, str[index + 1]);
			index++;
		}
		else
			length += ft_printchar(str[index]);
		index++;
	}
	va_end(args);
	return (length);
}
