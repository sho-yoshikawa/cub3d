/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:56:17 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/21 21:20:52 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <sysexits.h>
# include "./mlx.h"
# include "../Libft/libft.h"
# include "../Get_next_line/get_next_line.h"

# define POWER(a, b) ((a - b) * (a - b))
# define DIST(a, b, c, d) (sqrt(POWER(a, c) + POWER(b, d)))
# define GAUSS(a) (floor(a / TILE_SIZE) * TILE_SIZE)

# define PI M_PI
# define TWO_PI (2 * PI)
# define HALF_PI (PI / 2)
# define FOV (60 * PI / 180)
# define MOVE_SPEED 0.25
# define TURN_SPEED (6 * PI / 180)
# define TILE_SIZE 1
# define ERROR -1
# define SUCCESS 1

# define KEY_ESC 53
# define KEY_WINX 264
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROYNOTIFY 17
# define NOEVENTMASK 0L
# define KEYPRESSMASK 1L << 0
# define KEYRELEASEMASK 1L << 1

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct	s_tex {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		width;
	int		height;
}				t_tex;

typedef struct	s_pl
{
	double	x;
	double	y;
	double	z;
	bool	p_flag;
	int		turn_dir;
	int		walk_dir;
	int		sidewalk_dir;
	double	rot;
	double	step;
}				t_pl;

typedef struct	s_sprite
{
	double	x;
	double	y;
	double	distance;
	double	corr_dist;
	double	angle;
	double	right_angle;
	double	left_angle;
}				t_sprite;

typedef struct	s_ray
{
	double	ray_angle;
	double	hwall_x;
	double	hwall_y;
	double	vwall_x;
	double	vwall_y;
	double	distance;
	bool	vwall_f;
	bool	hwall_f;
	bool	no_f;
	bool	so_f;
	bool	ea_f;
	bool	we_f;
}				t_ray;

typedef struct	s_cub
{
	int		window_width;
	int		window_height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*sp_path;
	int		f_color;
	int		c_color;
	char	*map[256];
	int		map_maxrow;
	int		map_maxcol;
	bool	win_f;
	bool	no_path_f;
	bool	so_path_f;
	bool	we_path_f;
	bool	ea_path_f;
	bool	sp_path_f;
	bool	f_color_f;
	bool	c_color_f;
	t_list	*lists;
}				t_cub;

typedef struct	s_info
{
	void	*mlx;
	void	*mlx_win;
	bool	save_flag;
	t_cub	cub;
	t_img	view;
	t_pl	player;
	t_ray	*rays;
	double	*zbuffer;
	double	dist_plane;
	t_tex	tex_north;
	t_tex	tex_south;
	t_tex	tex_west;
	t_tex	tex_east;
	t_tex	tex_sprite;
}				t_info;

typedef enum	e_spec_num
{
	R, NO, SO, WE, EA, S, F, C, MAP
}				t_spec_num;

typedef enum	e_err_num
{
	READ_ERROR,
	UNKNOWN_ERROR,
	MALLOC_ERROR,
	OPEN_ERROR,
	INVALID_ARG,
	INVALID_CUBFILE,
	INVALID_FORMAT,
	INVALID_RESO,
	INVALID_PATH,
	NO_INFO_FOUND,
	NO_PLAYER,
	MULTIPLE_ID,
	MULTIPLE_PLAYER,
	MAP_ISNT_CLOSED,
	HUGE_MAP,
	LESS_PARAMS,
	MAP_SELECT,
	NOT_SAVE_F,
	BROKEN_IMG,
	UNDER_MAP_INFO
}				t_err_num;

void			ft_argment_error(int argc, char **argv, t_info *info);
int				ft_cubfile_fmt(char *path);
void			ft_check_params(t_info *info);
int				ft_spec_multi(int spec, t_cub *cub);
void			ft_check_flag(t_info *info);
void			ft_error(int ret);
void			ft_init_info(int argc, char *argv[], t_info *info);
void			ft_init_flags(t_info *info);
void			ft_init_player(t_info *info);
void			ft_init_cub(t_info *info);
void			ft_init_structure(t_info *info);
int				ft_spec_map(char *line, t_cub *cub);
int				ft_perse_map(int fd, t_cub *cub);
int				ft_closed_map(t_cub *cub, int x, int y);
void			ft_check_map(t_info *info);
void			ft_player(t_info *info, int x, int y);
int				ft_spec_branch(char *line);
int				ft_perse_line(char *line, t_cub *cub);
int				ft_read_cub(char *argv, t_cub *cub);
int				ft_check_color(char **strs);
int				ft_spec_fc(char *line, int spec, t_cub *cub);
void			ft_check_path(t_cub *cub);
int				ft_spec_path(char *line, int spec, t_cub *cub);
int				ft_set_spec_flag(int spec, t_cub *cub);
int				ft_spec_r(char *line, t_cub *cub);
void			ft_sizecheck_r(t_info *info);
void			ft_sprite(t_cub *cub, int x, int y);
void			ft_texture(t_info *info);
void			ft_open_texture(t_info *info, t_tex *tex, char *path);
int				ft_strs_length(char **strs);
int				ft_isdigit_char(char *str);
void			ft_floodfill(t_cub *cub, int x, int y);

int				ft_loop(t_info *info);
int				ft_keypress_hook(int keycode, t_info *info);
void			ft_clear_background(t_info *info);
double			ft_rat_x(t_ray ray);
void			ft_render_wall2(int i, t_info *info);
void			ft_render_wall(t_info *info);
bool			ft_sprite_in_fov(double angle, t_sprite *sprite);
void			ft_render_sprite(t_info *info);
int				ft_sprite_tex(t_info *info, t_sprite *sp,
									double x_rat, double y_rat);
double			ft_sprite_rot_x(t_ray ray, t_sprite *sprite);
void			ft_draw_sprite2(t_info *info, t_sprite *sp, int i);

void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				get_color(char c, int trgb);
double			ft_fix_angle(double rot);

void			ft_move_player(t_info *info);
int				ft_collision(t_cub cub, double x, double y);
void			ft_rot_step(t_info *info);
void			ft_sprite_calc(t_list *items, t_pl player);

void			ft_raydirection(t_ray *ray);
void			ft_dist_cmp(t_ray *ray, t_pl player);
void			ft_check_rays(t_info *info, int i);
void			ft_raycasting(t_info *info);
void			ft_check_hor(t_ray *ray, t_pl player, t_cub cub);
void			ft_collision_hor(double x, double y, t_cub cub, t_ray *ray);
void			ft_check_ver(t_ray *ray, t_pl player, t_cub cub);
void			ft_collision_ver(double x, double y, t_cub cub, t_ray *ray);

void			ft_sort_sprite(t_list *items);
void			ft_draw_sprite(t_info *info, t_sprite *sprite);
t_list			*ft_long_dist_sp(t_list *lst_index);

t_tex			ft_which_texture(t_ray ray, t_info *info);
int				ft_wall_tex(t_info *info, int i,
								double x_ratio, double y_ratio);
void			ft_error(int ret);
int				ft_end(t_info *info);
void			ft_all_free_split(char **strs);

int				ft_keyrelease_hook(int keycode, t_info *info);
void			ft_reset_dir(int keycode, t_info *info);

int				ft_atoi_for_fc(char *str);
int				ft_atoi_for_r(char *str);
int				ft_check_comma(char *s);
void			ft_re_read_cubfile(int fd);

void			ft_export(t_info *info);
void			ft_file_header(int fd, t_img view);
void			ft_info_header(int fd, t_img view);
void			ft_bmp_data(t_img *img, int width, int height, int fd);

#endif
