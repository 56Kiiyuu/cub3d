/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:04:14 by gchalmel          #+#    #+#             */
/*   Updated: 2026/04/29 14:27:47 by gchalmel         ###   ########.fr       */
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

int	ft_isspace(char *line, int i)
{
	while ((line[i] != '\0') && (line[i] == ' ' || line[i] == '\f'
			|| line[i] == '\n' || line[i] == '\r'
			|| line[i] == '\t' || line[i] == '\v'))
		i++;
	return (i);
}

void	ft_parse(const char *filename, t_data *data)
{
	int		size_filename;
	int		fd;
	char	*line;
	int		i;

	(void)data;
	size_filename = ft_strlen(filename);
	if (ft_strncmp(&filename[size_filename - 4], ".cub", 5))
		exit(ft_error("parse.c", ERR_PARSER_EXTENSION));
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		i = ft_isspace(line, i);
		if (!ft_strncmp(&line[i], "NO", 3))
			ft_fill_no();
		else if (!ft_strncmp(&line[i], "SO", 3))
			ft_fill_so();
		else if (!ft_strncmp(&line[i], "WE", 3))
			ft_fill_we();
		else if (!ft_strncmp(&line[i], "EA", 3))
			ft_fill_ea();
		line = get_next_line(fd);
	}

}
