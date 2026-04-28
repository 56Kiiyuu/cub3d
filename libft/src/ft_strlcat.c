/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:08:12 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/10 17:37:28 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	end;
	size_t	index_src;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	end = 0;
	while (dest[end])
		end++;
	index_src = 0;
	while (src[index_src] && (index_src + end + 1) < (len))
	{
		dest[end + index_src] = src[index_src];
		index_src++;
	}
	if (index_src < len)
		dest[end + index_src] = '\0';
	if (len <= dest_len)
		return (ft_strlen(src) + len);
	else
		return (ft_strlen(src) + dest_len);
	return (dest_len + src_len);
}
