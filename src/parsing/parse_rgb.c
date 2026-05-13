/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:44:13 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/13 14:44:17 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

/*GET VALUE RGB (check missing value or invalid)*/
int	get_color_val(t_data *data, char *line, int *i)
{
	int	val;
	int	len;

	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	len = 0;
	while (line[*i + len] && ft_isdigit(line[*i + len]))
		len++;
	if (len == 0 || len > 3)
		clean_exit(data, ft_error("parse_rgb.c", PARSING_NO_COLOR));
	val = ft_atoi(&line[*i]);
	if (val < 0 || val > 255)
		clean_exit(data, ft_error("parse_rgb.c", ERR_PARSER_BAD_NUMBER_RGB));
	*i += len;
	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	return (val);
}

/*PARSING RGB*/
void	parse_rgb(t_data *data, int *rgb, char *line)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	i = 0;
	red = get_color_val(data, line, &i);
	if (line[i++] != ',')
		clean_exit(data, ft_error("parse_rgb.c", ERR_PARSER_BAD_NUMBER_RGB));
	green = get_color_val(data, line, &i);
	if (line[i++] != ',')
		clean_exit(data, ft_error("parse_rgb.c", ERR_PARSER_BAD_NUMBER_RGB));
	blue = get_color_val(data, line, &i);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != '\0' && line[i] != '\n')
		clean_exit(data, ft_error("parse_rgb.c", PARSING_NO_COLOR));
	*rgb = (red << 16 | green << 8 | blue);
}
