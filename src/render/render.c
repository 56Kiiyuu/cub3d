/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiiyuu <kiiyuu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:15:04 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/07 14:09:29 by kiiyuu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_pixel_put_custom(t_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dest = img->addr + (y * img->len_line + x * (img->pixel_bits / 8));
	*(unsigned int *)dest = color;
}

void	render_bg(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				mlx_pixel_put_custom(&data->img, x, y, data->params.ceiling_color);
			else
				mlx_pixel_put_custom(&data->img, x, y, data->params.floor_color);
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	move_player(data);
	render_bg(data);
	raycasting(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
