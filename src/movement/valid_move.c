/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:03:55 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/29 18:23:39 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// Check X
// Check Y
// Fonction a modif pour le parsing
int	validate_move(t_data *data, double newX, double newY)
{
	int	moved;

	moved = 0;
	if (worldMAP[(int)newX][(int)data->player->posY] == 0)
	{
		data->player->posX = newX;
		moved = 1;
	}
	if (worldMAP[(int)data->player->posX][(int)newY] == 0)
	{
		data->player->posY = newY;
		moved = 1;
	}
	return (moved);
}
