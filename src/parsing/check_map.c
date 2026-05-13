/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:44:58 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/13 13:34:07 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	is_valid_case(t_data *data, int i, int j, int max_w)
{
	if (i == 0 || i == data->map_size_y - 1 || j == 0 || j == max_w - 1)
		clean_exit(data, ft_error("check_map.c", PARSING_MAP_OPEN_BORDERS));
	if (data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' ' ||
		data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' ')
		clean_exit(data, ft_error("check_map.c", PARSING_MAP_OPEN_EMPTY));
}

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	has_door;
	int	max_w;

	i = 0;
	has_door = 0;
	while (i < data->map_size_y)
	{
		j = 0;
		max_w = ft_strlen(data->map[i]);
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'D')
				has_door = 1;
			if (ft_strchr("0NSEW", data->map[i][j])
				|| (BONUS && data->map[i][j] == 'D'))
				is_valid_case(data, i, j, max_w);
			j++;
		}
		i++;
	}
	if (BONUS && has_door && !data->params.do_path)
		clean_exit(data, ft_error("check_map.c", PARSING_NO_TEX_DOORS));
}
