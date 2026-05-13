/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:04:14 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/13 15:07:00 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	ft_init_param(t_fileinfo *fi)
{
	fi->ea_path = NULL;
	fi->no_path = NULL;
	fi->so_path = NULL;
	fi->we_path = NULL;
	fi->do_path = NULL;
	fi->ceiling_color = -1;
	fi->floor_color = -1;
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

/* HANDLE LINE KEYS */
void	handle_line_content(t_data *data, char *line, int i, int *is_map)
{
	if (!ft_strncmp(&line[i], "NO", 2))
		data->params.no_path = ft_fill_data_info(data, &line[i + 2]);
	else if (!ft_strncmp(&line[i], "SO", 2))
		data->params.so_path = ft_fill_data_info(data, &line[i + 2]);
	else if (!ft_strncmp(&line[i], "WE", 2))
		data->params.we_path = ft_fill_data_info(data, &line[i + 2]);
	else if (!ft_strncmp(&line[i], "EA", 2))
		data->params.ea_path = ft_fill_data_info(data, &line[i + 2]);
	else if (BONUS && !ft_strncmp(&line[i], "DO", 2))
		data->params.do_path = ft_fill_data_info(data, &line[i + 2]);
	else if (!ft_strncmp(&line[i], "F", 1) && !(*is_map))
		parse_rgb(data, &data->params.floor_color, &line[i + 1]);
	else if (!ft_strncmp(&line[i], "C", 1) && !(*is_map))
		parse_rgb(data, &data->params.ceiling_color, &line[i + 1]);
	else if (!ft_strncmp(&line[i], "1", 1) || !ft_strncmp(&line[i], " ", 1))
	{
		*is_map = 1;
		data->map_size_y++;
	}
	else if (line[i] != '\n' && line[i] != '\0')
		clean_exit(data, ft_error("parse.c", ERR_PARSER_BAD_KEYWORD));
}

/*
	return size of map
*/
int	ft_loop_parse(const char *filename, t_data *data)
{
	char	*line;
	int		i;
	int		is_map;

	data->fd = open(filename, O_RDONLY);
	if (data->fd < 0)
		clean_exit(data, ft_error("parse.c", PARSING_NOT_OPEN_FILE));
	is_map = 0;
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		data->tmp_line = line;
		i = 0;
		while (line[i] && ft_isspace(line[i]))
			i++;
		handle_line_content(data, line, i, &is_map);
		free(line);
		data->tmp_line = NULL;
	}
	close(data->fd);
	data->fd = -1;
	return (data->map_size_y);
}

void	ft_parse(const char *filename, t_data *data)
{
	int		size_filename;

	ft_init_param(&data->params);
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
