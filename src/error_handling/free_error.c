/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:37:29 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/20 16:50:48 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_err(char **err)
{
	int	i;

	i = 0;
	if (err == NULL)
		return ;
	while (i < 23)
	{
		if (err[i] == NULL)
		{
			i++;
			continue ;
		}
		free(err[i]);
		i++;
	}
	free(err);
}
