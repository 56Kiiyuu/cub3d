/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:54:00 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 18:26:47 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		double	cameraX = 2 * x / (double)WIN_WIDTH - 1;
		double	raydirx = data->player->dirX + data->player->planeX * cameraX;
		double	raydiry = data->player->dirY + data->player->planeY * cameraX;
		int		mapX = (int)data->player->posX;
		int		mapY = (int)data->player->posY;

		double	distX = fabs(1 / raydirx);
		double	distY = fabs(1 / raydiry);

		double	sidedistX;
		double	sidedistY;
		int		stepX;
		int		stepY;
		int		hit = 0; //Si on touche un mur;
		int		side; //Direction (N,S,E,W)

		//calcul des distance au spawn
		if (raydirx < 0)
		{
			stepX = -1;
			sidedistX = (data->player->posX - mapX) * distX;
		}
		else
		{
			stepX = 1;
			sidedistX = (mapX + 1.0 - data->player->posX) * distX;
		}
		if (raydiry < 0)
		{
			stepY = -1;
			sidedistY = (data->player->posY - mapY) * distY;
		}
		else
		{
			stepY = 1;
			sidedistY = (mapY + 1.0 - data->player->posY) * distY;
		}
		// on check si on touche le mur (DDA)
		while (hit == 0)
		{
			if (sidedistX < sidedistY)
			{
				sidedistX += distX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sidedistY += distY;
				mapY += stepY;
				side = 1;
			}
			if (mapX < 0 || mapX >= 8 || mapY < 0 || mapY >= 8)
				break ;
			if (worldMAP[mapX][mapY] > 0)
				hit = 1;
		}
		// tracage du mur
		double	perpWallDist;
		if (side == 0)
			perpWallDist = (sidedistX - distX);
		else
			perpWallDist = (sidedistY - distY);
		int	lineheight = (int)(WIN_HEIGHT / perpWallDist);

		int	drawstart = -lineheight / 2 + WIN_HEIGHT / 2;
		if (drawstart < 0)
			drawstart = 0;
		int	drawend = lineheight / 2 + WIN_HEIGHT / 2;
		if (drawend >= WIN_HEIGHT)
			drawend = WIN_HEIGHT - 1;
		int	color = 0x2E2E2D;
		if (side == 1)
			color = 0xAA0000;

		draw_colon(data, x, drawstart, drawend, color);
		x++;
	}
}
