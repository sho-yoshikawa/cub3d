/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:48:23 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 12:23:44 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_info	info;

	ft_init_structure(&info);
	info.mlx = mlx_init();
	ft_init_info(argc, argv, &info);
	if (info.save_flag == false)
		info.mlx_win = mlx_new_window(
			info.mlx, info.view.width, info.view.height, "syoshika_cub3d");
	info.view.img_ptr = mlx_new_image(
					info.mlx, info.view.width, info.view.height);
	info.view.addr = mlx_get_data_addr(info.view.img_ptr,
		&info.view.bpp, &info.view.len, &info.view.endian);
	if (info.save_flag == true)
		ft_export(&info);
	mlx_loop_hook(info.mlx, ft_loop, &info);
	mlx_hook(info.mlx_win, KEYPRESS, KEYPRESSMASK,
										ft_keypress_hook, &info);
	mlx_hook(info.mlx_win, KEYRELEASE, KEYRELEASEMASK,
										ft_keyrelease_hook, &info);
	mlx_hook(info.mlx_win, DESTROYNOTIFY, NOEVENTMASK, ft_end, &info);
	mlx_loop(info.mlx);
	return (0);
}
