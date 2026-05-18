/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:31:35 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/18 18:15:23 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*DRAW SQUARE FOR MINIMAP*/
void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MM_CASE_SIZE)
	{
		j = 0;
		while (j < MM_CASE_SIZE)
		{
			if (i == 0 || j == 0)
				mlx_pixel_put_custom(&data->img, x + j, y + i, 0x000000);
			else
				mlx_pixel_put_custom(&data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

/*DRAW LINE FOR MINIMAP (start[int x1, int y1], end[int x2, int y2])*/
void	draw_line_minimap(t_data *data, int start[2], int end[2])
{
	double	delta[2];
	double	step;
	double	x;
	double	y;

	delta[0] = end[0] - start[0];
	delta[1] = end[1] - start[1];
	step = fabs(delta[1]);
	if (fabs(delta[0]) > fabs(delta[1]))
		step = fabs(delta[0]);
	delta[0] /= step;
	delta[1] /= step;
	x = start[0];
	y = start[1];
	while (step-- >= 0)
	{
		mlx_pixel_put_custom(&data->img, (int)x, (int)y, 0x00FF0000);
		x += delta[0];
		y += delta[1];
	}
}

int	get_minimap_color(t_data *data, int x, int y)
{
	if (y < 0 || y >= data->map_size_y || x < 0 || !data->map[y][x]
		|| data->map[y][x] == ' ')
		return (0x000000);
	if (data->map[y][x] == '1')
		return (0x666666);
	if (data->map[y][x] == 'D')
		return (0x2B00FF);
	return (0x222222);
}

void	draw_player_minimap(t_data *data)
{
	int	pos[2];
	int	dir[2];
	int	i;
	int	j;
	int	radius;

	radius = 10;
	pos[0] = (radius * MM_CASE_SIZE) + MM_OFFSET + (MM_CASE_SIZE / 2);
	pos[1] = (radius * MM_CASE_SIZE) + MM_OFFSET + (MM_CASE_SIZE / 2);
	i = -3;
	while (++i < 2)
	{
		j = -3;
		while (++j < 2)
			mlx_pixel_put_custom(&data->img, pos[0] + j,
				pos[1] + i, 0x00FF0000);
	}
	dir[0] = pos[0] + (data->player->dir_x * 10);
	dir[1] = pos[1] + (data->player->dir_y * 10);
	draw_line_minimap(data, pos, dir);
}

void	draw_minimap(t_data *data)
{
	int	player_pos[2];
	int	screen[2];
	int	radius;

	radius = 10;
	player_pos[1] = -(radius + 1);
	while (++player_pos[1] <= radius)
	{
		player_pos[0] = -6;
		while (++player_pos[0] <= radius)
		{
			screen[0] = (player_pos[0] + radius) * MM_CASE_SIZE + MM_OFFSET;
			screen[1] = (player_pos[1] + radius) * MM_CASE_SIZE + MM_OFFSET;
			draw_square(data, screen[0], screen[1], get_minimap_color(data,
					(int)data->player->pos_x + player_pos[0],
					(int)data->player->pos_y + player_pos[1]));
		}
	}
	draw_player_minimap(data);
}
