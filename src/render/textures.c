/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:50:34 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/18 18:22:38 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**/
int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (3);
		return (2);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (1);
		return (0);
	}
}

void	get_texture_coords(t_data *data, t_ray *ray, int *tex_x, int tex_id)
{
	if (ray->side == 0)
		ray->wall_x = data->player->pos_y + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		ray->wall_x = data->player->pos_x + ray->perp_wall_dist
			* ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	*tex_x = (int)(ray->wall_x * (double)data->texture[tex_id].width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		*tex_x = data->texture[tex_id].width - *tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
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
		tex_id = 4;
	else
		tex_id = get_texture_index(ray);
	get_texture_coords(data, ray, &tex_x, tex_id);
	step = 1.0 * data->texture[tex_id].height / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
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
