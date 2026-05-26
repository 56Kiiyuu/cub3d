/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:04:14 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/26 16:44:33 by kevlim           ###   ########.fr       */
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

/*
	return size of map
*/
int	ft_loop_parse(const char *filename, t_data *data)
{
	char	*line;
	int		i;

	data->fd = open(filename, O_RDONLY);
	if (data->fd < 0)
		clean_exit(data, ft_error("parse.c", PARSING_NOT_OPEN_FILE), NULL);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		i = 0;
		ft_line_handler(data, line, &i);
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
		clean_exit(data, ft_error("parse.c", ERR_PARSER_EXTENSION), NULL);
	data->map_size_y = 0;
	ft_loop_parse(filename, data);
	data->is_map = 0;
	data->map_end = 0;
	parse_map(data, data->map_size_y, filename);
	parse_spawn(data);
	check_map(data);
	if (data->params.ceiling_color == -1 || data->params.floor_color == -1)
		clean_exit(data, ft_error("parse.c", PARSING_NO_COLOR), NULL);
	if (data->params.no_path == NULL || data->params.so_path == NULL
		|| data->params.we_path == NULL || data->params.ea_path == NULL)
		clean_exit(data, ft_error("parse.c", NO_TEXTURE), NULL);
}
