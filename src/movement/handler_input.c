/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:02:12 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/31 12:15:17 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	toggle_door(t_data *data)
{
	int	dx;
	int	dy;

	dx = (int)(data->player->pos_x + data->player->dir_x * 0.5);
	dy = (int)(data->player->pos_y + data->player->dir_y * 0.5);
	if (data->map[dy][dx] == 'D')
		data->map[dy][dx] = 'O';
	else if (data->map[dy][dx] == 'O')
		data->map[dy][dx] = 'D';
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		quit_cub3d(data);
	if (keycode == 'w')
		data->player->move_y = 1;
	if (keycode == 's')
		data->player->move_y = -1;
	if (keycode == 'a')
		data->player->move_x = -1;
	if (keycode == 'd')
		data->player->move_x = 1;
	if (keycode == 65361)
		data->player->rotate = -1;
	if (keycode == 65363)
		data->player->rotate = 1;
	if (BONUS && keycode == 'e')
		toggle_door(data);
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == 'w')
		data->player->move_y = 0;
	if (keycode == 's')
		data->player->move_y = 0;
	if (keycode == 'a')
		data->player->move_x = 0;
	if (keycode == 'd')
		data->player->move_x = 0;
	if (keycode == 65361)
		data->player->rotate = 0;
	if (keycode == 65363)
		data->player->rotate = 0;
	return (0);
}

/*BONUS*/
int	handle_mouse(int x, int y, t_data *data)
{
	int		diff;
	double	mouse_speed;

	(void)y;
	diff = x - (WIN_WIDTH / 2);
	if (diff != 0)
	{
		mouse_speed = diff * 0.001;
		rotate_left_right(data, mouse_speed);
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (0);
}
