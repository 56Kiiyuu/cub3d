/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:02:12 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/12 15:29:24 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	toggle_door(t_data *data)
{
	int	dx;
	int	dy;

	//Check case in front player
	dx = (int)(data->player->posX + data->player->dirX * 0.5);
	dy = (int)(data->player->posY + data->player->dirY * 0.5);

	if (data->map[dy][dx] == 'D')
		data->map[dy][dx] = 'O'; //OPEN
	else if (data->map[dy][dx] == 'O')
		data->map[dy][dx] = 'D'; //CLOSE
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		quit_cub3d(data);
	if (keycode == 'w')
		data->player->moveY = 1;// FORWARD
	if (keycode == 's')
		data->player->moveY = -1;// BACKWARD
	if (keycode == 'a')
		data->player->moveX = -1;// LEFT
	if (keycode == 'd')
		data->player->moveX = 1;// RIGHT
	if (keycode == 65361)
		data->player->rotate = -1;// TURN LEFT
	if (keycode == 65363)
		data->player->rotate = 1;// TURN RIGHT
	if (BONUS && keycode == 'e')
		toggle_door(data);
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == 'w')
		data->player->moveY = 0;// FORWARD
	if (keycode == 's')
		data->player->moveY = 0;// BACKWARD
	if (keycode == 'a')
		data->player->moveX = 0;// LEFT
	if (keycode == 'd')
		data->player->moveX = 0;// RIGHT
	if (keycode == 65361)
		data->player->rotate = 0;// TURN LEFT
	if (keycode == 65363)
		data->player->rotate = 0;// TURN RIGHT
	if (BONUS && keycode == 'e')
		toggle_door(data);
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
