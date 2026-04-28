/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:51:42 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/24 15:02:57 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uintlen(unsigned int n)
{
	int	uintlen;

	uintlen = 0;
	while (n != 0)
	{
		uintlen++;
		n = n / 10;
	}
	return (uintlen);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	int		len;

	len = ft_uintlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (n != 0)
	{
		res[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

int	ft_printuint(unsigned int n)
{
	int		length;
	char	*res;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		res = ft_unsigned_itoa(n);
		length += ft_printstr(res);
	}
	free(res);
	return (length);
}
