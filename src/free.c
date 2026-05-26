/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:21:12 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/26 17:00:36 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures_path(t_data *data)
{
	if (data->params.no_path)
		free(data->params.no_path);
	if (data->params.so_path)
		free(data->params.so_path);
	if (data->params.we_path)
		free(data->params.we_path);
	if (data->params.ea_path)
		free(data->params.ea_path);
	if (BONUS && data->params.do_path)
		free(data->params.do_path);
}

void	free_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	i = 0;
	while (i < data->map_size_y)
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_gnl_stash(int fd)
{
	char	*line;

	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	free_textures(t_data *data)
{
	int	i;

	if (!data->mlx)
		return ;
	i = 0;
	while (i < 5)
	{
		if (data->texture[i].img)
		{
			mlx_destroy_image(data->mlx, data->texture[i].img);
			data->texture[i].img = NULL;
		}
		i++;
	}
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
	}
}

void	free_parse_data(t_data *data)
{
	free_map(data);
	free_textures_path(data);
}
