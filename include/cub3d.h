/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:22:23 by kevlim            #+#    #+#             */
/*   Updated: 2026/04/30 15:41:37 by gabch            ###   ########.fr       */
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
# define ROT_SPEED 0.02
# define MOVE_SPEED 0.03

/* FENETRE */
# define WIN_WIDTH 1280
# define WIN_HEIGHT 1024

/* ERRORS CODE*/
# define ERR_NOT_ENOUGHT_ARGS 0
# define ERR_PARSER_EXTENSION 1
# define ERR_MLX_START 2
# define ERR_MLX_WINDOW 3
# define ERR_PARSER_NOT_GOOD_PATH 4
# define ERR_PARSER_TEXTURE_DIRECTION 5
# define ERR_PARSER_MULTIPLE_TEXTURE 6
# define ERR_PARSER_EMPTY_PATH 7
# define ERR_PARSER_SPACE_PATH 8

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
	char	*addr;
	int		pixel_bits;
	int		len_line;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		moveX;
	int		moveY;
	int		rotate;
	char	direction;
}	t_player;


typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**map;
	t_fileinfo	params;
	t_player	*player;
	t_img		img;
}	t_data;

typedef struct s_ray
{
	double	cameraX;		//coord X (-1 to 1) where ray for pov
	double	rayDirX;		//direction X for ray
	double	rayDirY;		//direction Y for ray
	int		mapX;			//Pos X of ray in MAP
	int		mapY;			//Pos Y of ray in MAP
	double	sideDistX;		//distance X ray start to next case
	double	sideDistY;		//distance Y ray start to next case
	double	deltaDistX;		//distance X ray to cross next line vertical
	double	deltaDistY;		//distance Y ray to cross next line horizontal
	double	perpWallDist;	//used for fish-eye
	int		stepX;			//direction X we step on the grid
	int		stepY;			//direction Y we step on the grid
	int		side;			//boolean (0 if hit vertical, 1 if hit horizontal)
	int		lineHeight;		//height (pixels) of colon
	int		drawStart;		//pixel colon(upper)
	int		drawEnd;		//pixel colon(lower)
	double	wallX;
}	t_ray;


extern int worldMAP[8][8];

void	init_mlx(t_data *data);

int		render(t_data *data);
void	draw_colon(t_data *data, int x, int start, int end, int color);
void	raycasting(t_data *data);

/*MOVEMENT*/
void	init_player_direction(t_data *data);
int		move_player(t_data *data);
int		rotate_player(t_data *data, double rot_dir);
int		validate_move(t_data *data, double newX, double newY);
int		handle_keypress(int keycode, t_data *data);
int		handle_keyrelease(int keycode, t_data *data);

void	clean_exit(t_data *data, int code);
int		quit_cub3d(t_data *data);

int		error_msg(char *from, char *msg, int code);

// Parsing
void	ft_parse(const char *filename, t_data *data);
int		ft_isspace(char c);
void	ft_fill_data_info(char *str, char *line);
void	parse_map(t_data *data, int size_map, const char *filename);

// Error
int		ft_error(char *from, int code);

#endif
