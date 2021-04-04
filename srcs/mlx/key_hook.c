/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:56:04 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/08 08:06:41 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_keypress_hook(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->player.walk_dir = 1;
	else if (keycode == KEY_S)
		info->player.walk_dir = -1;
	else if (keycode == KEY_D)
		info->player.sidewalk_dir = 1;
	else if (keycode == KEY_A)
		info->player.sidewalk_dir = -1;
	else if (keycode == KEY_RIGHT)
		info->player.turn_dir = 1;
	else if (keycode == KEY_LEFT)
		info->player.turn_dir = -1;
	else if (keycode == KEY_ESC)
		ft_end(info);
	return (SUCCESS);
}

int		ft_keyrelease_hook(int keycode, t_info *info)
{
	if (keycode == KEY_W || keycode == KEY_S)
		info->player.walk_dir = 0;
	else if (keycode == KEY_A || keycode == KEY_D)
		info->player.sidewalk_dir = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		info->player.turn_dir = 0;
	return (SUCCESS);
}
