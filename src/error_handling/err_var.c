/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:25:31 by gchalmel          #+#    #+#             */
/*   Updated: 2026/05/27 18:47:10 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	***get_err(void)
{
	static char	**err = NULL;

	return (&err);
}

void	ft_fill_err_buff(char ***err)
{
	(*err)[0] = ft_strdup("Pas assez d'argument: ./cub3d <filename.cub>");
	(*err)[1] = ft_strdup("L'extension du fichier n'est pas .cub");
	(*err)[2] = ft_strdup("Not start MLX");
	(*err)[3] = ft_strdup("Not create window");
	(*err)[4] = ft_strdup("Path doit commencer par ./ ou /");
	(*err)[5] = ft_strdup("Texture direction incorrect Ex: NO <PATH>.xmp");
	(*err)[6] = ft_strdup("Doublons de texture");
	(*err)[7] = ft_strdup("Aucune PATH preciser pour la texture");
	(*err)[8] = ft_strdup("Les space sont interdites dans le PATH");
	(*err)[9] = ft_strdup("KeyWord inconnu ou mal placer");
	(*err)[10] = ft_strdup("Format de nombre rgb incorrect");
	(*err)[11] = ft_strdup("Plusieurs point de spawn ont ete detectes");
	(*err)[12] = ft_strdup("Aucun spawn n'a ete defini");
	(*err)[13] = ft_strdup("Map is wrong");
	(*err)[14] = ft_strdup("Aucune floor color et/ou ceiling color defini");
	(*err)[15] = ft_strdup("Manque une couleur RGB");
	(*err)[16] = ft_strdup("Door 'D' found but no DO texture");
	(*err)[17] = ft_strdup("Map open on borders");
	(*err)[18] = ft_strdup("Map open: empty space neighbor");
	(*err)[19] = ft_strdup("Failed to normalize map line");
	(*err)[20] = ft_strdup("Could not open file");
	(*err)[21] = ft_strdup("Malloc failed");
	(*err)[22] = ft_strdup("No texture found");
}

void	init_err(t_data *data)
{
	char	***err;

	err = get_err();
	*err = malloc(sizeof(char *) * 23);
	if (*err == NULL)
		clean_exit(data, MALLOC_ERR, NULL);
	ft_fill_err_buff(err);
	return ;
}
