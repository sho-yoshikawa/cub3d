/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:58:45 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/15 17:20:06 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rot_step(t_info *info)
{
	info->player.rot += info->player.turn_dir * TURN_SPEED;
	info->player.rot = ft_fix_angle(info->player.rot);
	if (info->player.walk_dir != 0)
		info->player.step = info->player.walk_dir * MOVE_SPEED;
	if (info->player.sidewalk_dir != 0)
		info->player.step = info->player.sidewalk_dir * MOVE_SPEED;
}

int		ft_collision(t_cub cub, double x, double y)
{
	int map_x;
	int map_y;

	map_x = (int)floor(x / TILE_SIZE);
	map_y = (int)floor(y / TILE_SIZE);
	if (map_x < 0 || map_y < 0 || map_y >= cub.map_maxrow ||
		map_x > (int)ft_strlen(cub.map[map_y]))
		return (1);
	if (cub.map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	ft_move_player(t_info *info)
{
	double	new_x;
	double	new_y;
	double	step;
	double	rot;

	ft_rot_step(info);
	step = info->player.step;
	rot = info->player.rot;
	new_x = info->player.x;
	new_y = info->player.y;
	if (info->player.walk_dir)
	{
		new_x = info->player.x + cos(rot) * step;
		new_y = info->player.y + sin(rot) * step;
	}
	if (info->player.sidewalk_dir)
	{
		new_x = info->player.x + cos(rot + HALF_PI) * step;
		new_y = info->player.y + sin(rot + HALF_PI) * step;
	}
	if (!ft_collision(info->cub, new_x, info->player.y))
		info->player.x = new_x;
	if (!ft_collision(info->cub, info->player.x, new_y))
		info->player.y = new_y;
}
