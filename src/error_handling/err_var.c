/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:25:31 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/27 19:32:39 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**get_err(void)
{
	static char	*err[23] = {
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
		"Manque une couleur RGB",
		"Door 'D' found but no DO texture",
		"Map open on borders",
		"Map open: empty space neighbor",
		"Failed to normalize map line",
		"Could not open file", "Malloc failed", "No texture found"
	};

	return (err);
}
