/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:01:42 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/29 18:36:43 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMAP[8][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

int	main(void)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("main.c", ERR_NOT_ENOUGHT_ARGS));
	ft_parse(av[1], &data);
	ft_memset(&data, 0, sizeof(t_data));
	init_mlx(&data);
	data.player = malloc(sizeof(t_player));
	if (!data.player)
		clean_exit(&data, error_msg("malloc", "Failed to allocate player", 1));
/*DEBUG START (need to erase)*/
	data.player->posX = 4.0;
	data.player->posY = 4.0;
	data.player->moveX = 0;
	data.player->moveY = 0;
	data.player->rotate = 0;
	data.player->direction = 'W';
	init_player_direction(&data);
	data.img.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.pixel_bits, &data.img.len_line, &data.img.endian);
	mlx_hook(data.win, 17, 0L, (int (*)(void))((void *)quit_cub3d), &data);
	mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.win, 3, 1L << 1, handle_keyrelease, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
