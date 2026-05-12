/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:50:00 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/12 15:42:05 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_error(char *from, int code)
{
	char *err[16] =
	{
		"Pas assez d'argument: ./cub3d <filename.cub>",
		"L'extension du fichier n'est pas .cub",
		"Not start MLX",
		"Not create window",
		"Path doit commencer par ./ ou /",
		"Texture direction incorrect Ex: NO <PATH>.xmp",
		"Doublons de texture",
		"Aucune PATH preciser pour la texture",
		"Les space sont interdites dans le PATH",
		"KeyWord inconnu ou mal placer",
		"Format de nombre rgb incorrect",
		"Plusieurs point de spawn ont ete detectes",
		"Aucun spawn n'a ete defini",
		"Map is wrong",
		"Aucune floor color et/ou ceiling color defini",
		"Door 'D' found but no DO texture"
	};

	return (error_msg(from, err[code], code));
}

int	error_msg(char *from, char *msg, int code)
{
	ft_putstr_fd("cub3D: Error", 2);
	if (from)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(from, 2);
	}
	if (msg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
	}
	ft_putstr_fd("\n", 2);
	return (code);
}
