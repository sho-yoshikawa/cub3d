/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:44:36 by syoshika          #+#    #+#             */
/*   Updated: 2021/02/21 19:19:29 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player(t_info *info, int x, int y)
{
	info->player.p_flag = true;
	info->player.x = x;
	info->player.y = y;
	if (info->cub.map[y][x] == 'N')
		info->player.rot = 270 * PI / 180;
	if (info->cub.map[y][x] == 'W')
		info->player.rot = 180 * PI / 180;
	if (info->cub.map[y][x] == 'S')
		info->player.rot = 90 * PI / 180;
	if (info->cub.map[y][x] == 'E')
		info->player.rot = 0;
	info->cub.map[y][x] = '0';
}
