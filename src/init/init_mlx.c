/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:47:04 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 15:00:47 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		clean_exit(data, error_msg("mlx", ERR_MLX_START, 1));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		clean_exit(data, error_msg("mlx", ERR_MLX_WINDOW, 1));
	return ;
}
