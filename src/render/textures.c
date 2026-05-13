/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:50:34 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/13 13:22:20 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**/
int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0) // check if is a side (WE or EA)
	{
		if (ray->rayDirX > 0)
			return (3); // EA
		return (2); // WE
	}
	else // else is (NO or SO)
	{
		if (ray->rayDirY > 0)
			return (1); // EA
		return (0); // WE
	}
}

void	get_texture_coords(t_data *data, t_ray *ray, int *tex_x, int tex_id)
{
	if (ray->side == 0)
		ray->wallX = data->player->posY + ray->perpWallDist * ray->rayDirY;
	else
		ray->wallX = data->player->posX + ray->perpWallDist * ray->rayDirX;
	ray->wallX -= floor(ray->wallX);
	*tex_x = (int)(ray->wallX * (double)data->texture[tex_id].width);
	if (ray->side == 0 && ray->rayDirX > 0)
		*tex_x = data->texture[tex_id].width - *tex_x - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		*tex_x = data->texture[tex_id].width - *tex_x - 1;
}

void	draw_textured_line(t_data *data, t_ray *ray, int x)
{
	int		tex_id;
	int		tex_x;
	int		tex_y;
	int		y;
	double	step;

	if (BONUS && ray->hit_type == 2)
		tex_id = 4; //index for doors
	else
		tex_id = get_texture_index(ray);
	get_texture_coords(data, ray, &tex_x, tex_id);
	step = 1.0 * data->texture[tex_id].height / ray->lineHeight;
	ray->tex_pos = (ray->drawStart - WIN_HEIGHT / 2
			+ ray->lineHeight / 2) * step;
	y = ray->drawStart;
	while (y < ray->drawEnd)
	{
		tex_y = (int)ray->tex_pos & (data->texture[tex_id].height - 1);
		ray->tex_pos += step;
		ray->color = *(unsigned int *)(data->texture[tex_id].addr
				+ (tex_y * data->texture[tex_id].len_line
					+ tex_x * (data->texture[tex_id].pixel_bits / 8)));
		mlx_pixel_put_custom(&data->img, x, y, ray->color);
		y++;
	}
}
