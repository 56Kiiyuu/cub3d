/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:20:24 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/13 17:24:37 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_fill_data_info(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		exit(ft_error("player_directions.c", ERR_PARSER_EMPTY_PATH));
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
		exit(ft_error("parse.c", ERR_PARSER_TEXTURE_DIRECTION));
	return (str);
}
