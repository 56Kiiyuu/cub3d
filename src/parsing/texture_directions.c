/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:20:24 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/20 16:44:45 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_data_info(t_data *data, char *line, char *str, int code)
{
	if (str != NULL)
		free(str);
	clean_exit(data, ft_error("texture_directions.c", code), line);
}

char	*ft_fill_data_info(t_data *data, char *line, char *full)
{
	int		i;
	char	*str;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		exit_data_info(data, full, NULL, ERR_PARSER_EMPTY_PATH);
	while (line[i] != '\0' && ft_isspace(line[i]))
		i++;
	if ((!(line[i] == '.') && !(line[i + 1] == '/')) && (!(line[i] == '/')))
		exit_data_info(data, full, NULL, ERR_PARSER_NOT_GOOD_PATH);
	str = ft_strdup(&line[i]);
	ft_check_null(data, str);
	i = 0;
	while (str[i] != '\0' && ft_isprint(str[i]))
	{
		if (ft_isspace(str[i]))
			exit_data_info(data, full, str, ERR_PARSER_SPACE_PATH);
		i++;
	}
	if (str[i] != '\0' && (str[i] != '\n'))
		exit_data_info(data, full, str, ERR_PARSER_TEXTURE_DIRECTION);
	str[i] = '\0';
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".xpm", 5))
		exit_data_info(data, full, str, ERR_PARSER_TEXTURE_DIRECTION);
	return (str);
}
