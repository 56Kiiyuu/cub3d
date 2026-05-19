/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:54:24 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/19 11:58:51 by kevlim           ###   ########.fr       */
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
	if (data->mlx && data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	free_parse_data(data);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->player)
		free(data->player);
	exit(code);
}

int	quit_cub3d(t_data *data)
{
	clean_exit(data, 0, NULL);
	return (0);
}
