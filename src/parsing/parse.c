/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:04:14 by gchalmel          #+#    #+#             */
/*   Updated: 2026/04/28 17:03:56 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	ft_parse(const char *filename, t_data *data)
{
	int	size_filename;

	(void)data;
	size_filename = ft_strlen(filename);
	printf("%s\n", &filename[size_filename - 4]);
	if (ft_strncmp(&filename[size_filename - 4], ".cub", 5))
	{
		exit(ft_error("parse.c", ERR_PARSER_EXTENSION));
	}
}
