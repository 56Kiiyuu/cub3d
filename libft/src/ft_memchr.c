/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:03:26 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/07 11:35:29 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*find;

	ptr = (unsigned char *)s;
	find = NULL;
	while ((s != NULL) && (n--))
	{
		if (*ptr != (unsigned char)c)
			ptr++;
		else
		{
			find = ptr;
			break ;
		}
	}
	return (find);
}
