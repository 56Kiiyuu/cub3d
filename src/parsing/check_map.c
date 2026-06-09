/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:46:18 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/09 16:58:41 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_case(t_data *data, int x, int y)
{
	if (!check_left(data, x, y))
		clean_exit(data, ft_error("map", PARSING_WRONG_MAP), NULL);
	else if (!check_right(data, x, y))
		clean_exit(data, ft_error("map", PARSING_WRONG_MAP), NULL);
	else if (!check_up(data, x, y))
		clean_exit(data, ft_error("map", PARSING_WRONG_MAP), NULL);
	else if (!check_down(data, x, y))
		clean_exit(data, ft_error("map", PARSING_WRONG_MAP), NULL);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_size_y)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (!ft_strchr("01 NSEW", data->map[i][j])
				&& !(BONUS && data->params.do_path
				&& ft_strchr("DO", data->map[i][j])))
				clean_exit(data, ft_error("map", PARSING_WRONG_MAP), NULL);
			if (data->map[i][j] == '0'
				|| (BONUS && data->params.do_path
				&& ft_strchr("DO", data->map[i][j])))
				check_case(data, j, i);
			j++;
		}
		i++;
	}
}
