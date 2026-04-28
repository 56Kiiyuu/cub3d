/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:01:42 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 15:00:55 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	init_mlx(&data);
	mlx_hook(data.win, 17, 0L, (int (*)(void))((void *)quit_cub3d), &data);
	mlx_loop(data.mlx);
	return (0);
}
