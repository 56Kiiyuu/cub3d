/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:20:24 by gchalmel          #+#    #+#             */
/*   Updated: 2026/04/30 16:12:08 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_fill_data_info(char *str, char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		exit(ft_error("player_directions.c", ERR_PARSER_EMPTY_PATH));
	if (str != NULL)
		exit(ft_error("player_directions.c", ERR_PARSER_MULTIPLE_TEXTURE));
	while (line[i] != '\0' && ft_isspace(line[i]))
		i++;
	if ((!(line[i] == '.') && !(line[i + 1] == '/')) && (!(line[i] == '/')))
		exit(ft_error("player_directions.c", ERR_PARSER_NOT_GOOD_PATH));
	str = ft_strdup(&line[i]);
	i = 0;
	while (str[i] != '\0' && ft_isprint(str[i]))
	{
		if (ft_isspace(str[i]))
			exit(ft_error("player_directions.c", ERR_PARSER_SPACE_PATH));
		i++;
	}
	if (str[i] != '\0' && (str[i] != '\n'))
		exit(ft_error("player_directions.c", ERR_PARSER_TEXTURE_DIRECTION));
	str[i] = '\0';
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".xpm", 5))
		exit(ft_error("parse.c", ERR_PARSER_EXTENSION));
	printf("%s\n", str);
}
