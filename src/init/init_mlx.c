/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:47:04 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 17:06:45 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		clean_exit(data, ft_error("mlx", ERR_MLX_START));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		clean_exit(data, ft_error("mlx", ERR_MLX_WINDOW));
	return ;
}
