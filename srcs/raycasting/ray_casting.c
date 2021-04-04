/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:05:45 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:32:09 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raydirection(t_ray *ray)
{
	if (0 < ray->ray_angle && ray->ray_angle < PI)
		ray->so_f = true;
	if (0.5 * PI < ray->ray_angle && ray->ray_angle < 1.5 * PI)
		ray->we_f = true;
	if (1.5 * PI <= ray->ray_angle || ray->ray_angle <= 0.5 * PI)
		ray->ea_f = true;
	if (PI <= ray->ray_angle && ray->ray_angle <= TWO_PI)
		ray->no_f = true;
}

void	ft_dist_cmp(t_ray *ray, t_pl player)
{
	double h_dist;
	double v_dist;

	if (ray->hwall_f == true)
		h_dist = DIST(player.x, player.y, ray->hwall_x, ray->hwall_y);
	else
		h_dist = INT_MAX;
	if (ray->vwall_f == true)
		v_dist = DIST(player.x, player.y, ray->vwall_x, ray->vwall_y);
	else
		v_dist = INT_MAX;
	if (h_dist < v_dist)
	{
		ray->vwall_f = false;
		ray->distance = h_dist;
	}
	else if (v_dist < h_dist)
	{
		ray->hwall_f = false;
		ray->distance = v_dist;
	}
}

void	ft_raycasting(t_info *info)
{
	double	ray_rot;
	int		i;

	i = 0;
	ft_bzero(info->rays, sizeof(t_ray) * (size_t)info->cub.window_width);
	ray_rot = info->player.rot - FOV / 2;
	while (i < info->cub.window_width)
	{
		info->rays[i].ray_angle = ft_fix_angle(ray_rot);
		ft_check_rays(info, i);
		ray_rot += FOV / info->cub.window_width;
		i++;
	}
}

void	ft_check_rays(t_info *info, int i)
{
	ft_raydirection(&info->rays[i]);
	ft_check_hor(&info->rays[i], info->player, info->cub);
	ft_check_ver(&info->rays[i], info->player, info->cub);
	ft_dist_cmp(&info->rays[i], info->player);
}
