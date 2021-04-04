/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:49:40 by syoshika          #+#    #+#             */
/*   Updated: 2021/02/21 19:25:38 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_info(int argc, char *argv[], t_info *info)
{
	ft_argment_error(argc, argv, info);
	ft_read_cub(argv[1], &info->cub);
	ft_check_map(info);
	ft_check_params(info);
	ft_texture(info);
	info->view.width = info->cub.window_width;
	info->view.height = info->cub.window_height;
	info->rays = ft_calloc((size_t)info->cub.window_width, sizeof(t_ray));
	info->zbuffer = ft_calloc((size_t)info->cub.window_width, sizeof(double));
	info->dist_plane = (info->cub.window_width / 2) / tan(FOV / 2);
}
