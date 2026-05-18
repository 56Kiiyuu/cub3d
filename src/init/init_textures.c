/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:46:54 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/18 19:17:30 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_xpm(t_data *data, t_img *tex, char *path)
{
	printf("Textures PATH: [%s]\n", path);
	tex->img = mlx_xpm_file_to_image(data->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		clean_exit(data, error_msg("t", "Failed to load XPM texture", 1), NULL);
	tex->addr = mlx_get_data_addr(tex->img, &tex->pixel_bits,
			&tex->len_line, &tex->endian);
}

void	init_textures(t_data *data)
{
	load_xpm(data, &data->texture[0], data->params.no_path);
	load_xpm(data, &data->texture[1], data->params.so_path);
	load_xpm(data, &data->texture[2], data->params.we_path);
	load_xpm(data, &data->texture[3], data->params.ea_path);
	if (BONUS && data->params.do_path)
		load_xpm(data, &data->texture[4], data->params.do_path);
	else
		data->texture[4].img = NULL;
}
