/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:04:14 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/11 15:58:11 by gchalmel         ###   ########.fr       */
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

/*
	return size of map
*/
int	ft_loop_parse(const char *filename, char *line, t_data *data)
{
	int (fd) = open(filename, O_RDONLY);
	int (size_map) = 0;
	int (i) = 0;
	int (is_map) = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0' && ft_isspace(line[i]))
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
			size_map++;
		}
		else if (!(line[i] == '\n') && !(line[i] == '\0'))
			exit(ft_error("parse.c", ERR_PARSER_BAD_KEYWORD));
		free(line);
		line = get_next_line(fd);
	}
	printf("Floor color %X\nCeiling color %X\n", data->params.floor_color, data->params.ceiling_color);
	return (size_map);
}

void	ft_parse(const char *filename, t_data *data)
{
	char	*line;
	int		size_filename;

	line = NULL;
	ft_init_param(&data->params);
	size_filename = ft_strlen(filename);
	if (ft_strncmp(&filename[size_filename - 4], ".cub", 5))
		exit(ft_error("parse.c", ERR_PARSER_EXTENSION));
	data->map_size_y = ft_loop_parse(filename, line, data);
	parse_map(data, data->map_size_y, filename);
	parse_spawn(data);
	check_map(data);
	if (data->params.ceiling_color == -1 || data->params.floor_color == -1)
		exit(ft_error("parse.c", PARSING_NO_COLOR));
}
