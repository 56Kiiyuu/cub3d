/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:43:07 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/05 14:43:23 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*ptr;
	int		size_src;

	size_src = 0;
	while (src[size_src])
		size_src++;
	dest = malloc(sizeof(char) * (size_src + 1));
	size_src = 0;
	ptr = dest;
	if (dest == NULL)
		return (NULL);
	while (src[size_src])
	{
		ptr[size_src] = src[size_src];
		size_src++;
	}
	ptr[size_src] = '\0';
	return (dest);
}
