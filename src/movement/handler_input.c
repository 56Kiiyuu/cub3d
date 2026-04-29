/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:02:12 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/29 18:23:31 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (0);
}
