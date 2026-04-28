/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:49:24 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/05 13:47:26 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i] && i + 1 < len)
	{
		dest[i] = src[i];
		i++;
	}
	if (len > 0)
	{
		dest[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}
