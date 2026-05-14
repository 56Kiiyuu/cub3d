/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:04:14 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/14 16:24:24 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	ft_init_param(t_data *data)
{
	data->params.ea_path = NULL;
	data->params.no_path = NULL;
	data->params.so_path = NULL;
	data->params.we_path = NULL;
	data->params.do_path = NULL;
	data->map_size_y = 0;
	data->params.ceiling_color = -1;
	data->params.floor_color = -1;
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	ft_line_handler(t_data *data, char *line)
{
	int (i) = 0;
	int (is_map) = 0;
	int (stop_parse) = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!ft_strncmp(&line[i], "NO", 2))
		data->params.no_path = ft_fill_data_info(&line[i + 2]);
	else if (!ft_strncmp(&line[i], "SO", 2))
		data->params.so_path = ft_fill_data_info(&line[i + 2]);
	else if (!ft_strncmp(&line[i], "WE", 2))
		data->params.we_path = ft_fill_data_info(&line[i + 2]);
	else if (!ft_strncmp(&line[i], "EA", 2))
		data->params.ea_path = ft_fill_data_info(&line[i + 2]);
	else if (!ft_strncmp(&line[i], "F", 1) && !is_map)
		parse_rgb(&data->params.floor_color, &line[i + 1]);
	else if (!ft_strncmp(&line[i], "C", 1) && !is_map)
		parse_rgb(&data->params.ceiling_color, &line[i + 1]);
	else if (!ft_strncmp(&line[i], "1", 1) || !ft_strncmp(&line[i], " ", 1))
	{
		is_map = 1;
		data->map_size_y++;
	}
	else if (is_map && !stop_parse)
		stop_parse = 1;
	else if (stop_parse && is_map)
		exit(ft_error("parse.c", ERR_PARSER_BAD_KEYWORD));
	else if (!(line[i] == '\n') && !(line[i] == '\0'))
		exit(ft_error("parse.c", ERR_PARSER_BAD_KEYWORD));
}

/*
	return size of map
*/
int	ft_loop_parse(const char *filename, t_data *data)
{
	char	*line;

	data->fd = open(filename, O_RDONLY);
	if (data->fd < 0)
		clean_exit(data, ft_error("parse.c", PARSING_NOT_OPEN_FILE));
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		ft_line_handler(data, line);
		free(line);
	}
	close(data->fd);
	data->fd = -1;
	return (data->map_size_y);
}

void	ft_parse(const char *filename, t_data *data)
{
	int		size_filename;

	ft_init_param(data);
	size_filename = ft_strlen(filename);
	if (ft_strncmp(&filename[size_filename - 4], ".cub", 5))
		clean_exit(data, ft_error("parse.c", ERR_PARSER_EXTENSION));
	data->map_size_y = 0;
	ft_loop_parse(filename, data);
	parse_map(data, data->map_size_y, filename);
	parse_spawn(data);
	check_map(data);
	if (data->params.ceiling_color == -1 || data->params.floor_color == -1)
		clean_exit(data, ft_error("parse.c", PARSING_NO_COLOR));
}
