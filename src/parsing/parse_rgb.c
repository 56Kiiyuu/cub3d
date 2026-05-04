/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:44:13 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/04 15:24:26 by gchalmel         ###   ########.fr       */
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

void	parse_rgb(int *rgb, char *line)
{
	int	i;
	int	cn;

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
		if ((cn > 3 || cn <= 0))
			exit(ft_error("parse_rgb.c", ERR_PARSER_BAD_NUMBER_RGB));
		*rgb = *rgb << 8 | ft_atoi(&line[i]);
		while (line[i] != '\0' && ft_isdigit(line[i]))
			i++;
	}
}
