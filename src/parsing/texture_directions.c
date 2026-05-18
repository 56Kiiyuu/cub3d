/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:20:24 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/18 19:31:19 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_fill_data_info(t_data *data, char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		clean_exit(data, ft_error("player_dir.c", ERR_PARSER_EMPTY_PATH), NULL);
	while (line[i] != '\0' && ft_isspace(line[i]))
		i++;
	if ((!(line[i] == '.') && !(line[i + 1] == '/')) && (!(line[i] == '/')))
		clean_exit(data, ft_error("play_dir", ERR_PARSER_NOT_GOOD_PATH), NULL);
	str = ft_strdup(&line[i]);
	ft_check_null(data, str);
	i = 0;
	while (str[i] != '\0' && ft_isprint(str[i]))
	{
		if (ft_isspace(str[i]))
			clean_exit(data, ft_error("play_dir", ERR_PARSER_SPACE_PATH), NULL);
		i++;
	}
	if (str[i] != '\0' && (str[i] != '\n'))
		clean_exit(data, ft_error("dir", ERR_PARSER_TEXTURE_DIRECTION), NULL);
	str[i] = '\0';
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".xpm", 5))
		clean_exit(data, ft_error("parse", ERR_PARSER_TEXTURE_DIRECTION), NULL);
	return (str);
}
