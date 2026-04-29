/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:14:40 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/29 18:23:37 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left_right(t_data *data, double rotate_speed)
{
	t_player	*p;
	double		tmp_x;

	p = data->player;
	tmp_x = p->dirX;
	p->dirX = p->dirX * cos(rotate_speed) - p->dirY * sin(rotate_speed);
	p->dirY = tmp_x * sin(rotate_speed) + p->dirY * cos(rotate_speed);
	tmp_x = p->planeX;
	p->planeX = p->planeX * cos(rotate_speed) - p->planeY * sin(rotate_speed);
	p->planeY = tmp_x * sin(rotate_speed) + p->planeY * cos(rotate_speed);
	return (1);
}

int	rotate_player(t_data *data, double rot_dir)
{
	int		moved;
	double	rotate_speed;

	moved = 0;
	rotate_speed = ROT_SPEED * rot_dir;
	moved += rotate_left_right(data, rotate_speed);
	return (moved);
}
