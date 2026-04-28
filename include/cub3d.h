/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:22:23 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/28 17:11:52 by gchalmel         ###   ########.fr       */
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

/* ERRORS CODE*/
# define ERR_NOT_ENOUGHT_ARGS 0
# define ERR_PARSER_EXTENSION 1
# define ERR_MLX_START 2
# define ERR_MLX_WINDOW 3

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_fileinfo
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_rgb	floor_color;
	t_rgb	ceiling_color;
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

// Parsing
void	ft_parse(const char *filename, t_data *data);

// Error
int		ft_error(char *from, int code);

#endif

