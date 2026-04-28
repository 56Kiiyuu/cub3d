/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:07:45 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/17 17:22:15 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long long n)
{
	int	ptrlen;

	ptrlen = 0;
	while (n != 0)
	{
		ptrlen++;
		n = n / 16;
	}
	return (ptrlen);
}

void	ft_putptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		length += write(1, "0x", 2);
		ft_putptr(ptr);
		length += ft_ptrlen(ptr);
	}
	return (length);
}
