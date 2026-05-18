/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:07:36 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/18 18:13:10 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

static void	handler(t_data *data, char *line, int *i, int *vn)
{
	while (line[*i] && ft_isspace(line[*i]))
		*i += 1;
	if (!ft_strncmp(&line[*i], "NO", 2))
		data->params.no_path = ft_fill_data_info(&line[*i + 2]);
	else if (BONUS && !ft_strncmp(&line[*i], "DO", 2))
		data->params.do_path = ft_fill_data_info(&line[*i + 2]);
	else if (!ft_strncmp(&line[*i], "SO", 2))
		data->params.so_path = ft_fill_data_info(&line[*i + 2]);
	else if (!ft_strncmp(&line[*i], "WE", 2))
		data->params.we_path = ft_fill_data_info(&line[*i + 2]);
	else if (!ft_strncmp(&line[*i], "EA", 2))
		data->params.ea_path = ft_fill_data_info(&line[*i + 2]);
	else if (!ft_strncmp(&line[*i], "F", 1) && !vn[0])
		parse_rgb(&data->params.floor_color, &line[*i + 1]);
	else if (!ft_strncmp(&line[*i], "C", 1) && !vn[0])
		parse_rgb(&data->params.ceiling_color, &line[*i + 1]);
	else if (!ft_strncmp(&line[*i], "1", 1) || !ft_strncmp(&line[*i], " ", 1))
	{
		vn[0] = 1;
		data->map_size_y++;
	}
	else if (vn[0] && !vn[1])
		vn[1] = 1;
	else if ((!(line[*i] == '\n') && !(line[*i] == '\0')) || (vn[1] && vn[0]))
		exit(ft_error("parse.c", ERR_PARSER_BAD_KEYWORD));
}

/*
vn[0] = is_map (if one we are in the map)
vn[1] = sp (if one whe have possibly \n or a bad keyword in the map parse)
*/
void	ft_line_handler(t_data *data, char *line, int *i)
{
	int	var_norminette[2];

	var_norminette[0] = 0;
	var_norminette[1] = 0;
}
