/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:04:39 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/31 12:06:31 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_background(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->cub.window_height / 2)
	{
		j = 0;
		while (j < info->cub.window_width)
		{
			my_mlx_pixel_put(&info->view, j, i, info->cub.c_color);
			j++;
		}
		i++;
	}
	while (i < info->cub.window_height)
	{
		j = 0;
		while (j < info->cub.window_width)
		{
			my_mlx_pixel_put(&info->view, j, i, info->cub.f_color);
			j++;
		}
		i++;
	}
}

double	ft_rat_x(t_ray ray)
{
	double x_rat;

	if (ray.no_f && ray.hwall_f)
		x_rat = fmod(ray.hwall_x, TILE_SIZE) / TILE_SIZE;
	if (ray.so_f && ray.hwall_f)
		x_rat = 1 - fmod(ray.hwall_x, TILE_SIZE) / TILE_SIZE;
	if (ray.ea_f && ray.vwall_f)
		x_rat = fmod(ray.vwall_y, TILE_SIZE) / TILE_SIZE;
	if (ray.we_f && ray.vwall_f)
		x_rat = 1 - fmod(ray.vwall_y, TILE_SIZE) / TILE_SIZE;
	return (x_rat);
}

void	ft_render_wall2(int i, t_info *info)
{
	double	w_height;
	double	x_rat;
	double	y_rat;
	int		w_start;
	int		j;

	info->zbuffer[i] = info->rays[i].distance
		* cos(info->rays[i].ray_angle - info->player.rot);
	w_height = (TILE_SIZE / info->zbuffer[i]) * info->dist_plane;
	w_start = round((info->cub.window_height / 2) - (w_height / 2));
	x_rat = ft_rat_x(info->rays[i]);
	j = w_start > 0 ? w_start : 0;
	while (j < info->cub.window_height && (j < (w_height + w_start)))
	{
		y_rat = (j - w_start) / w_height;
		my_mlx_pixel_put(&info->view, i, j,
			ft_wall_tex(info, i, x_rat, y_rat));
		j++;
	}
}

void	ft_render_wall(t_info *info)
{
	int		i;

	i = 0;
	ft_clear_background(info);
	while (i < info->cub.window_width)
	{
		ft_render_wall2(i, info);
		i++;
	}
}
