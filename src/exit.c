/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:54:24 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/27 19:17:34 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_exit(t_data *data, int code, char *line)
{
	if (!data)
		exit(code);
	if (line)
		free(line);
	if (data->tmp_line)
		free(data->tmp_line);
	if (data->fd > 0)
		free_gnl_stash(data->fd);
	free_parse_data(data);
	if (data->player)
		free(data->player);
	free_textures(data);
	if (data->mlx)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(code);
}

int	quit_cub3d(t_data *data)
{
	clean_exit(data, 0, NULL);
	return (0);
}
