/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:46:50 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/19 11:48:04 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*CALCUL initials steps and length*/
void	setup_dda(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	step_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

/*DDA algorithm*/
void	process_dda(t_ray *ray, t_data *data)
{
	int		hit;
	char	c;

	hit = 0;
	while (hit == 0)
	{
		step_ray(ray);
		if (ray->map_y < 0 || ray->map_y >= data->map_size_y
			|| ray->map_x < 0 || data->map[ray->map_y][ray->map_x] == '\0')
			break ;
		c = data->map[ray->map_y][ray->map_x];
		if (c == '1')
			hit = 1;
		else if (BONUS && c == 'D' && data->texture[4].img != NULL)
			hit = 2;
	}
	ray->hit_type = hit;
}
