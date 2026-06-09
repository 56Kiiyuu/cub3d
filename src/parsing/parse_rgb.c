/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:44:13 by gchalmel          #+#    #+#             */
/*   Updated: 2026/06/09 15:37:45 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

int	count_number(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && ft_isdigit(line[i]))
		i++;
	return (i);
}

void	valid_rgb(t_data *data, int *rgb, char *line, char *full)
{
	int	cn;
	int	val;

	cn = count_number(line);
	if ((cn > 3 || cn <= 0))
		clean_exit(data, ft_error("rgb", ERR_PARSER_BAD_NUMBER_RGB), full);
	val = ft_atoi(line);
	if (val < 0 || val > 255)
		clean_exit(data, ft_error("rgb", ERR_PARSER_BAD_NUMBER_RGB), full);
	*rgb = (*rgb << 8) | val;
}

/*PARSING RGB*/
void	parse_rgb(t_data *data, int *rgb, char *line, char *full)
{
	int	i;

	int (count_rgb) = 0;
	i = 0;
	*rgb = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		while (line[i] != '\0' && ft_isspace(line[i]))
			i++;
		if (line[i] == ',')
		{
			i++;
			while (line[i] != '\0' && ft_isspace(line[i]))
				i++;
		}
		valid_rgb(data, rgb, &line[i], full);
		count_rgb++;
		while (line[i] != '\0' && ft_isdigit(line[i]))
			i++;
	}
	if (count_rgb != 3)
		clean_exit(data, ft_error("parse_rgb.c", PARSING_NO_3_COLOR), full);
}
