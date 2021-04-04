/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:07:12 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:35:17 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_collision_hor(double x, double y, t_cub cub, t_ray *ray)
{
	double	x_step;
	double	y_step;
	double	x_check;
	double	y_check;

	y_step = ray->no_f ? -TILE_SIZE : TILE_SIZE;
	x_step = TILE_SIZE / tan(ray->ray_angle);
	if ((ray->we_f && x_step > 0) || (ray->ea_f && x_step < 0))
		x_step *= -1;
	ray->hwall_f = false;
	while ((0 <= x && x <= cub.map_maxcol * TILE_SIZE) &&
			(0 <= y && y <= cub.map_maxrow * TILE_SIZE))
	{
		x_check = x;
		y_check = y + (ray->no_f ? -1 : 0);
		if (ft_collision(cub, x_check, y_check))
		{
			ray->hwall_f = true;
			ray->hwall_x = x;
			ray->hwall_y = y;
			break ;
		}
		x += x_step;
		y += y_step;
	}
}

void	ft_check_hor(t_ray *ray, t_pl player, t_cub cub)
{
	double	x;
	double	y;

	y = GAUSS(player.y);
	if (ray->so_f)
		y += TILE_SIZE;
	x = (y - player.y) / tan(ray->ray_angle) + player.x;
	ft_collision_hor(x, y, cub, ray);
}

void	ft_collision_ver(double x, double y, t_cub cub, t_ray *ray)
{
	double	x_step;
	double	y_step;
	double	x_check;
	double	y_check;

	x_step = ray->we_f ? -TILE_SIZE : TILE_SIZE;
	y_step = TILE_SIZE * tan(ray->ray_angle);
	if ((ray->no_f && y_step > 0) || (ray->so_f && y_step < 0))
		y_step *= -1;
	ray->vwall_f = false;
	while ((0 <= x && x <= cub.map_maxcol * TILE_SIZE)
		&& (0 <= y && y <= cub.map_maxrow * TILE_SIZE))
	{
		x_check = x + (ray->we_f ? -1 : 0);
		y_check = y;
		if (ft_collision(cub, x_check, y_check))
		{
			ray->vwall_f = true;
			ray->vwall_x = x;
			ray->vwall_y = y;
			break ;
		}
		x += x_step;
		y += y_step;
	}
}

void	ft_check_ver(t_ray *ray, t_pl player, t_cub cub)
{
	double	x;
	double	y;

	x = GAUSS(player.x);
	if (ray->ea_f)
		x += TILE_SIZE;
	y = (x - player.x) * tan(ray->ray_angle) + player.y;
	ft_collision_ver(x, y, cub, ray);
}
