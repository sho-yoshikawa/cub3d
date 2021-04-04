/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_get_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:51:06 by syoshika          #+#    #+#             */
/*   Updated: 2021/04/03 12:51:09 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tex	ft_which_texture(t_ray ray, t_info *info)
{
	t_tex	tex;

	if (ray.no_f && ray.hwall_f)
		tex = info->tex_north;
	if (ray.so_f && ray.hwall_f)
		tex = info->tex_south;
	if (ray.ea_f && ray.vwall_f)
		tex = info->tex_east;
	if (ray.we_f && ray.vwall_f)
		tex = info->tex_west;
	return (tex);
}

int		ft_wall_tex(t_info *info, int i, double x_rat, double y_rat)
{
	int		x;
	int		y;
	int		color;
	char	*addr;
	t_tex	tex;

	tex = ft_which_texture(info->rays[i], info);
	x = round(x_rat * tex.width);
	y = round(y_rat * tex.height);
	addr = (char *)tex.addr;
	color = *(int *)(addr + y * tex.len + x * (tex.bpp / 8));
	return (color);
}

int		ft_sprite_tex(t_info *info, t_sprite *sp, double x_rat, double y_rat)
{
	int		x;
	int		y;
	int		color;
	char	*addr;
	t_tex	tex;

	(void)sp;
	tex = info->tex_sprite;
	x = round(x_rat * tex.width);
	y = round(y_rat * tex.height);
	addr = (char *)tex.addr;
	color = *(int *)(addr + y * tex.len + x * (tex.bpp / 8));
	return (color);
}
