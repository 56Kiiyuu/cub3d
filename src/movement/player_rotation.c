/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:14:40 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/18 18:01:51 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left_right(t_data *data, double rotate_speed)
{
	t_player	*p;
	double		tmp_x;

	p = data->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotate_speed) - p->dir_y * sin(rotate_speed);
	p->dir_y = tmp_x * sin(rotate_speed) + p->dir_y * cos(rotate_speed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotate_speed) - p->plane_y
		* sin(rotate_speed);
	p->plane_y = tmp_x * sin(rotate_speed) + p->plane_y * cos(rotate_speed);
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
