/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:01:42 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 17:02:17 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("main.c", ERR_NOT_ENOUGHT_ARGS));
	ft_parse(av[1], &data);
	ft_memset(&data, 0, sizeof(t_data));
	init_mlx(&data);
	mlx_hook(data.win, 17, 0L, (int (*)(void))((void *)quit_cub3d), &data);
	mlx_loop(data.mlx);
	return (0);
}
