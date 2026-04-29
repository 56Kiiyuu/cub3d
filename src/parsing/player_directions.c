/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:20:24 by gchalmel          #+#    #+#             */
/*   Updated: 2026/04/29 17:22:48 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_fill_no(t_fileinfo *fi, char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		exit(ft_error("player_directions.c", ERR_PARSER_EMPTY_PATH));
	if (fi->no_path != NULL)
		exit(ft_error("player_directions.c", ERR_PARSER_MULTIPLE_TEXTURE));
	while (line[i] != '\0' && ft_isspace(line[i]))
		i++;
	if ((!(line[i] == '.') && !(line[i + 1] == '/')) && (!(line[i] == '/')))
		exit(ft_error("player_directions.c", ERR_PARSER_NOT_GOOD_PATH));
	fi->no_path = &line[i];
	while (line[i] != '\0' && ft_isprint(line[i]))
	{
		if (ft_isspace(line[i]))
			exit(ft_error("player_directions.c", ERR_PARSER_SPACE_PATH));
		i++;
	}
	if (line[i] != '\0' && (line[i] != '\n'))
		exit(ft_error("player_directions.c", ERR_PARSER_TEXTURE_DIRECTION));
	printf("%s\n", fi->no_path);
}

/*void	ft_fill_so(t_fileinfo *fi)
{

}

void	ft_fill_we(t_fileinfo *fi)
{

}
void	ft_fill_ea(t_fileinfo *fi)
{

}*/
