/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:04:14 by gchalmel          #+#    #+#             */
/*   Updated: 2026/04/29 16:55:34 by gchalmel         ###   ########.fr       */
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
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	ft_parse(const char *filename, t_data *data)
{
	int		size_filename;
	int		fd;
	char	*line;
	int		i;

	ft_init_param(&data->params);
	size_filename = ft_strlen(filename);
	if (ft_strncmp(&filename[size_filename - 4], ".cub", 5))
		exit(ft_error("parse.c", ERR_PARSER_EXTENSION));
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0' && ft_isspace(line[i]))
			i++;
		if (!ft_strncmp(&line[i], "NO", 2))
			ft_fill_no(&data->params, &line[i + 2]);
		/*else if (!ft_strncmp(&line[i], "SO", 3))
			ft_fill_so();
		else if (!ft_strncmp(&line[i], "WE", 3))
			ft_fill_we();
		else if (!ft_strncmp(&line[i], "EA", 3))
			ft_fill_ea();*/
		line = get_next_line(fd);
	}

}
