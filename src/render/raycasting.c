/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:54:00 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/04 15:54:00 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
void	process_dda(t_ray *ray, t_data *data)
{
	int		hit;
	char	*current_line;

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
		if (ray->mapY < 0 || ray->mapY >= data->map_size_y)
			break ;
		current_line = data->map[ray->mapY];
		if (ray->mapX < 0 || current_line[ray->mapX] == '\0')
			break ;
		if (current_line[ray->mapX] == '1')
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
		process_dda(&ray, data);
		calculate_line_h(&ray, data->player);
		color = 0x2E2E2D;
		if (ray.side == 1)
			color = 0xAA0000;
		draw_textured_line(data, &ray, x);
		x++;
	}
}
