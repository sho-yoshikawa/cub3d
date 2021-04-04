/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:41:23 by syoshika          #+#    #+#             */
/*   Updated: 2021/02/21 19:07:27 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_flags(t_info *info)
{
	info->save_flag = false;
	info->cub.win_f = false;
	info->cub.no_path_f = false;
	info->cub.so_path_f = false;
	info->cub.we_path_f = false;
	info->cub.ea_path_f = false;
	info->cub.sp_path_f = false;
	info->cub.f_color_f = false;
	info->cub.c_color_f = false;
}

void	ft_init_player(t_info *info)
{
	info->player.x = 0;
	info->player.y = 0;
	info->player.z = TILE_SIZE / 2;
	info->player.p_flag = false;
	info->player.turn_dir = 0;
	info->player.walk_dir = 0;
	info->player.sidewalk_dir = 0;
	info->player.rot = 0.0;
}

void	ft_init_cub(t_info *info)
{
	info->cub.window_width = 640;
	info->cub.window_height = 480;
	info->cub.no_path = NULL;
	info->cub.so_path = NULL;
	info->cub.we_path = NULL;
	info->cub.ea_path = NULL;
	info->cub.sp_path = NULL;
	info->cub.f_color = 0;
	info->cub.c_color = 0;
	info->cub.map[0] = NULL;
	info->cub.map_maxrow = 0;
	info->cub.map_maxcol = 0;
	info->cub.lists = NULL;
}

void	ft_init_structure(t_info *info)
{
	ft_init_cub(info);
	ft_init_flags(info);
	ft_init_player(info);
	info->rays = NULL;
}
