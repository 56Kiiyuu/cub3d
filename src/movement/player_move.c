/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:02:10 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/29 18:23:35 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_data *data)
{
	double	newX;
	double	newY;

	newX = data->player->posX + data->player->dirX * MOVE_SPEED;
	newY = data->player->posY + data->player->dirY * MOVE_SPEED;
	return (validate_move(data, newX, newY));
}

int	move_backward(t_data *data)
{
	double	newX;
	double	newY;

	newX = data->player->posX - data->player->dirX * MOVE_SPEED;
	newY = data->player->posY - data->player->dirY * MOVE_SPEED;
	return (validate_move(data, newX, newY));
}

int	move_left(t_data *data)
{
	double	newX;
	double	newY;

	newX = data->player->posX + data->player->dirY * MOVE_SPEED;
	newY = data->player->posY - data->player->dirX * MOVE_SPEED;
	return (validate_move(data, newX, newY));
}

int	move_right(t_data *data)
{
	double	newX;
	double	newY;

	newX = data->player->posX - data->player->dirY * MOVE_SPEED;
	newY = data->player->posY + data->player->dirX * MOVE_SPEED;
	return (validate_move(data, newX, newY));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	// FORWARD
	if (data->player->moveY == 1)
		moved += move_forward(data);
	// BACKWARD
	if (data->player->moveY == -1)
		moved += move_backward(data);
	// LEFT
	if (data->player->moveX == -1)
		moved += move_left(data);
	// RIGHT
	if (data->player->moveX == 1)
		moved += move_right(data);
	// Rotation
	if (data->player->rotate != 0)
		moved += rotate_player(data, data->player->rotate);
	return (moved);
}
