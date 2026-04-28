/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:47:06 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/17 16:02:37 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned int n)
{
	int	hexalen;

	hexalen = 0;
	while (n != 0)
	{
		hexalen++;
		n = n / 16;
	}
	return (hexalen);
}

void	ft_puthexa(unsigned int n, const char type)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, type);
		ft_puthexa(n % 16, type);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (type == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (type == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(n, format);
	return (ft_hexalen(n));
}
