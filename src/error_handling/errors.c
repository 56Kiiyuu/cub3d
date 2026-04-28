/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:50:00 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 17:05:18 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_error(char *from, int code)
{
	char *err[4] =
	{
		"Pas assez d'argument: ./cub3d <filename.cub>",
		"L'extension du fichier n'est pas .cub",
		"Not start MLX",
		"Not create window"
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
