/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:44:13 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/20 16:28:47 by gchalmel         ###   ########.fr       */
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

/*PARSING RGB*/
void	parse_rgb(t_data *data, int *rgb, char *line, char *full)
{
	int	i;
	int	cn;

	int (count_rgb) = 0;
	i = 0;
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
		cn = count_number(&line[i]);
		count_rgb++;
		if ((cn > 3 || cn <= 0))
			clean_exit(data, ft_error("rgb", ERR_PARSER_BAD_NUMBER_RGB), full);
		*rgb = *rgb << 8 | ft_atoi(&line[i]);
		while (line[i] != '\0' && ft_isdigit(line[i]))
			i++;
	}
	if (count_rgb != 3)
		clean_exit(data, ft_error("parse_rgb.c", PARSING_NO_3_COLOR), full);
}
