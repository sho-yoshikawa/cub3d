/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:51:05 by syoshika          #+#    #+#             */
/*   Updated: 2021/02/21 19:26:24 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_open_texture(t_info *info, t_tex *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(info->mlx, path,
		&tex->width, &tex->height);
	if (tex->img_ptr == NULL)
		ft_error(BROKEN_IMG);
	tex->addr = mlx_get_data_addr(tex->img_ptr,
		&tex->bpp, &tex->len, &tex->endian);
}

void	ft_texture(t_info *info)
{
	ft_open_texture(info, &info->tex_north, info->cub.so_path);
	ft_open_texture(info, &info->tex_south, info->cub.no_path);
	ft_open_texture(info, &info->tex_west, info->cub.ea_path);
	ft_open_texture(info, &info->tex_east, info->cub.we_path);
	ft_open_texture(info, &info->tex_sprite, info->cub.sp_path);
}
