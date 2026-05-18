/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:02:10 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/18 18:00:44 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x + data->player->dir_x * MOVE_SPEED;
	new_y = data->player->pos_y + data->player->dir_y * MOVE_SPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x - data->player->dir_x * MOVE_SPEED;
	new_y = data->player->pos_y - data->player->dir_y * MOVE_SPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x + data->player->dir_y * MOVE_SPEED;
	new_y = data->player->pos_y - data->player->dir_x * MOVE_SPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x - data->player->dir_y * MOVE_SPEED;
	new_y = data->player->pos_y + data->player->dir_x * MOVE_SPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player->move_y == 1)
		moved += move_forward(data);
	if (data->player->move_y == -1)
		moved += move_backward(data);
	if (data->player->move_x == -1)
		moved += move_left(data);
	if (data->player->move_x == 1)
		moved += move_right(data);
	if (data->player->rotate != 0)
		moved += rotate_player(data, data->player->rotate);
	return (moved);
}
