/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:19:26 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/15 16:20:24 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_loop(t_info *info)
{
	ft_move_player(info);
	ft_sprite_calc(info->cub.lists, info->player);
	ft_raycasting(info);
	ft_render_wall(info);
	ft_render_sprite(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->view.img_ptr, 0, 0);
	mlx_do_sync(info->mlx);
	return (SUCCESS);
}
