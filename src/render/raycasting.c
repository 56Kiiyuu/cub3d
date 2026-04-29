/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:54:00 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/29 18:36:52 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
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
*/

/*Fonctions decoupees*/
/*INIT data ray*/

void	init_ray_data(int x, t_ray *ray, t_player *player)
{
	ray->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	ray->rayDirX = player->dirX + player->planeX * ray->cameraX;
	ray->rayDirY = player->dirY + player->planeY * ray->cameraX;
	ray->mapX = (int)player->posX;
	ray->mapY = (int)player->posY;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
}

/*CALCUL initials steps and length*/
void	setup_dda(t_ray *ray, t_player *player)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - player->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - player->posY) * ray->deltaDistY;
	}
}

/*DDA algorithm*/
void	process_dda(t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (ray->mapX < 0 || ray->mapX >= 8 || ray->mapY < 0 || ray->mapY >= 8)
			break ;
		if (worldMAP[ray->mapX][ray->mapY] > 0)
			hit = 1;
	}
}

/*Calculate HEIGHT*/
void	calculate_line_h(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
	else
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
	ray->lineHeight = (int)(WIN_HEIGHT / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + WIN_HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + WIN_HEIGHT / 2;
	if (ray->drawEnd >= WIN_HEIGHT)
		ray->drawEnd = WIN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wallX = player->posY + ray->perpWallDist * ray->rayDirY;
	else
		ray->wallX = player->posX + ray->perpWallDist * ray->rayDirX;
	ray->wallX -= floor(ray->wallX);
}

/*MAIN FUNCTION*/
void	raycasting(t_data *data)
{
	t_ray	ray;
	int		x;
	int		color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_data(x, &ray, data->player);
		setup_dda(&ray, data->player);
		process_dda(&ray);
		calculate_line_h(&ray, data->player);
		color = 0x2E2E2D;
		if (ray.side == 1)
			color = 0xAA0000;
		draw_colon(data, x, ray.drawStart, ray.drawEnd, color);
		x++;
	}
}
