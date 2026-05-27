/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:01:42 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/27 17:21:11 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_elements(t_data *data)
{
	data->player->rotate = 0;
	init_player_direction(data);
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.pixel_bits,
			&data->img.len_line, &data->img.endian);
}

/*HOOKS*/
// mlx_mouse_hide(data->mlx, data->win);
void	setup_mlx_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0L, (void *)quit_cub3d, data);
	mlx_hook(data->win, 2, 1L << 0, (void *)handle_keypress, data);
	mlx_hook(data->win, 3, 1L << 1, (void *)handle_keyrelease, data);
	if (BONUS)
	{
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		mlx_hook(data->win, 6, 1L << 6, (void *)handle_mouse, data);
	}
	mlx_loop_hook(data->mlx, (void *)render, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("main.c", ERR_NOT_ENOUGHT_ARGS));
	ft_memset(&data, 0, sizeof(t_data));
	data.fd = -1;
	data.player = ft_calloc(1, sizeof(t_player));
	if (!data.player)
		clean_exit(&data, error_msg("malloc", "Failed to allocate player", 1),
			NULL);
	ft_parse(av[1], &data);
	init_mlx(&data);
	init_textures(&data);
	init_game_elements(&data);
	setup_mlx_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
