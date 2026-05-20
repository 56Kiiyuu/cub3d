/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:22:23 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/20 16:49:52 by gchalmel         ###   ########.fr       */
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

/* RULES */
# ifndef BONUS
#  define BONUS 1
# endif

/* MACROS */
# define FALSE 0
# define TRUE 1
# define ROT_SPEED 0.02
# define MOVE_SPEED 0.03

/* FENETRE */
# define WIN_WIDTH 1280
# define WIN_HEIGHT 1024

/*MINIMAP*/
# define MM_CASE_SIZE 10
# define MM_OFFSET 20

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
# define ERR_PARSER_BAD_KEYWORD 9
# define ERR_PARSER_BAD_NUMBER_RGB 10
# define ERR_PARSER_MANY_SPAWN 11
# define ERR_PARSER_NO_SPAWN 12
# define PARSING_WRONG_MAP 13
# define PARSING_NO_COLOR 14
# define PARSING_NO_3_COLOR 15
# define PARSING_NO_TEX_DOORS 16
# define PARSING_MAP_OPEN_BORDERS 17
# define PARSING_MAP_OPEN_EMPTY 18
# define PARSING_NORMALIZE_MAP 19
# define PARSING_NOT_OPEN_FILE 20
# define MALLOC_ERR 21
# define NO_TEXTURE 22

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
	char	*do_path;
	int		floor_color;
	int		ceiling_color;
}	t_fileinfo;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		len_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move_x;
	int		move_y;
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
	int			map_size_y;
	t_fileinfo	params;
	t_player	*player;
	t_img		img;
	t_img		texture[5];
	t_img		door_tex;
	int			fd;
	char		*tmp_line;
}	t_data;

typedef struct s_ray
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	double			tex_pos;
	unsigned int	color;
	int				hit_type;
}	t_ray;

void	init_mlx(t_data *data);
void	init_textures(t_data *data);

int		render(t_data *data);
void	mlx_pixel_put_custom(t_img *img, int x, int y, int color);
void	setup_dda(t_ray *ray, t_player *player);
void	process_dda(t_ray *ray, t_data *data);
void	raycasting(t_data *data);
void	draw_minimap(t_data *data);
void	draw_textured_line(t_data *data, t_ray *ray, int x);

/*MOVEMENT*/
void	init_player_direction(t_data *data);
int		move_player(t_data *data);
int		rotate_left_right(t_data *data, double rotate_speed);
int		rotate_player(t_data *data, double rot_dir);
int		validate_move(t_data *data, double newX, double newY);
int		handle_keypress(int keycode, t_data *data);
int		handle_keyrelease(int keycode, t_data *data);
int		handle_mouse(int x, int y, t_data *data);

void	clean_exit(t_data *data, int code, char *line);
int		quit_cub3d(t_data *data);

int		error_msg(char *from, char *msg, int code);

// Parsing
void	ft_parse(const char *filename, t_data *data);
int		ft_isspace(char c);
char	*ft_fill_data_info(t_data *data, char *line, char *full);
void	parse_map(t_data *data, int size_map, const char *filename);
void	parse_rgb(t_data *data, int *rgb, char *line, char *full);
void	parse_spawn(t_data *data);
void	check_map(t_data *data);
void	ft_line_handler(t_data *data, char *line, int *i);

// Error
int		ft_error(char *from, int code);
void	ft_free_err(char **err);
void	ft_check_null(t_data *data, char *str);

// Free
void	free_textures_path(t_data *data);
void	free_map(t_data *data);
void	free_gnl_stash(int fd);
void	free_textures(t_data *data);
void	free_parse_data(t_data *data);

#endif
