/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:58:28 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/07 13:10:34 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
