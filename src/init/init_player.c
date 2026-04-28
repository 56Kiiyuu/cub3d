/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:09:22 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 17:44:25 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_data *data)
{
	data->player->posX = 4.0;
	data->player->posY = 4.0;

	data->player->dirX = 1.0;
	data->player->dirY = 0.0;

	data->player->planeX = 0.0;
	data->player->planeY = 0.0;
}
