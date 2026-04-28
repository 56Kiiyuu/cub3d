/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:02:12 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 18:03:28 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keycode, t_data *data)
{
	double oldDirX;
	double oldPlaneX;
	double rotSpeed = 0.1;  // vitesse de rotation
	double moveSpeed = 0.2; // vitesse de marche

	if (keycode == 65307) // ESC
		quit_cub3d(data);

	if (keycode == 'w')
	{
		if (worldMAP[(int)(data->player->posX + data->player->dirX * moveSpeed)][(int)data->player->posY] == 0)
			data->player->posX += data->player->dirX * moveSpeed;
		if (worldMAP[(int)data->player->posX][(int)(data->player->posY + data->player->dirY * moveSpeed)] == 0)
			data->player->posY += data->player->dirY * moveSpeed;
	}
	if (keycode == 's')
	{
		if (worldMAP[(int)(data->player->posX - data->player->dirX * moveSpeed)][(int)data->player->posY] == 0)
			data->player->posX -= data->player->dirX * moveSpeed;
		if (worldMAP[(int)data->player->posX][(int)(data->player->posY - data->player->dirY * moveSpeed)] == 0)
			data->player->posY -= data->player->dirY * moveSpeed;
	}
	if (keycode == 'd' || keycode == 65363)
	{
		oldDirX = data->player->dirX;
		data->player->dirX = data->player->dirX * cos(-rotSpeed) - data->player->dirY * sin(-rotSpeed);
		data->player->dirY = oldDirX * sin(-rotSpeed) + data->player->dirY * cos(-rotSpeed);
		oldPlaneX = data->player->planeX;
		data->player->planeX = data->player->planeX * cos(-rotSpeed) - data->player->planeY * sin(-rotSpeed);
		data->player->planeY = oldPlaneX * sin(-rotSpeed) + data->player->planeY * cos(-rotSpeed);
	}
	if (keycode == 'a' || keycode == 65361)
	{
		oldDirX = data->player->dirX;
		data->player->dirX = data->player->dirX * cos(rotSpeed) - data->player->dirY * sin(rotSpeed);
		data->player->dirY = oldDirX * sin(rotSpeed) + data->player->dirY * cos(rotSpeed);
		oldPlaneX = data->player->planeX;
		data->player->planeX = data->player->planeX * cos(rotSpeed) - data->player->planeY * sin(rotSpeed);
		data->player->planeY = oldPlaneX * sin(rotSpeed) + data->player->planeY * cos(rotSpeed);
	}
	return (0);
}
