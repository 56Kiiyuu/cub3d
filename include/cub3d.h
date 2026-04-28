/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:22:23 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 15:02:52 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

/* MACROS */
# define FALSE 0
# define TRUE 1

/* FENETRE */
# define WIN_WIDTH 1280
# define WIN_HEIGHT 1024

/* MSG ERRORS*/

# define ERR_MLX_START "Not start MLX"
# define ERR_MLX_WINDOW "Not create window"

typedef struct s_fileinfo
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color;
	int		ceiling_color;
}	t_fileinfo;


typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		len_line;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**map;
	t_fileinfo	params;
}	t_data;

void	init_mlx(t_data *data);

void	clean_exit(t_data *data, int code);
int		quit_cub3d(t_data *data);

int		error_msg(char *from, char *msg, int code);
#endif

