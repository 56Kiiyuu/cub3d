/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:51:54 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/27 17:31:24 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// a recheck
int	get_max_width(t_data *data, char **map, int size_y)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	if (!map || !*map)
		clean_exit(data, ft_error("check null", MALLOC_ERR), NULL);
	while (i < size_y)
	{
		if ((int)ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	normalize_map(t_data *data)
{
	int		i;
	int		max_w;
	char	*new_line;
	int		curr_len;

	i = 0;
	max_w = get_max_width(data, data->map, data->map_size_y);
	while (i < data->map_size_y)
	{
		curr_len = ft_strlen(data->map[i]);
		new_line = malloc(sizeof(char) * (max_w + 1));
		if (!new_line)
			clean_exit(data, ft_error("malloc", PARSING_NORMALIZE_MAP), NULL);
		ft_strlcpy(new_line, data->map[i], curr_len + 1);
		while (curr_len < max_w)
			new_line[curr_len++] = ' ';
		new_line[max_w] = '\0';
		free(data->map[i]);
		data->map[i] = new_line;
		i++;
	}
}

void	ft_add_map_line(t_data *data, char *line, int i)
{
	int	len;

	data->map[i] = ft_strdup(line);
	ft_check_null(data, data->map[i]);
	len = ft_strlen(data->map[i]);
	if (len > 0 && data->map[i][len - 1] == '\n')
		data->map[i][len - 1] = '\0';
}
