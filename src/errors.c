/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:50:00 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 15:00:51 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
