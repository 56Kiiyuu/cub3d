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

char	*ft_check_path_extension(t_data *data, char *str)
{
	int	len;
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]) && str[i] != '\n')
		i++;
	str[i] = '\0';
	len = ft_strlen(str);
	if (len < 5 || ft_strncmp(&str[len - 4], ".xpm", 5))
	{
		free(str);
		clean_exit(data, ft_error("parse.c", ERR_PARSER_EXTENSION));
	}
	return (str);
}

char	*ft_fill_data_info(t_data *data, char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		clean_exit(data, ft_error("text_directions.c", ERR_PARSER_EMPTY_PATH));
	if ((line[i] != '.' || line[i + 1] != '/') && (line[i] != '/'))
		clean_exit(data, ft_error("text_directions.c", ERR_PARSER_NOT_GOOD_PATH));
	str = ft_strdup(&line[i]);
	if (!str)
		clean_exit(data, ft_error("text_directions.c", MALLOC_ERR));
	i = -1;
	while (str[++i] && ft_isprint(str[i]))
	{
		if (ft_isspace(str[i]))
		{
			free(str);
			clean_exit(data, ft_error("text_directions.c", ERR_PARSER_SPACE_PATH));
		}
	}
	return (ft_check_path_extension(data, str));
}
