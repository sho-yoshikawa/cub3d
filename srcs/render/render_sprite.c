/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:14:07 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/31 13:10:30 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_sprite_in_fov(double angle, t_sprite *sprite)
{
	if (sprite->left_angle < sprite->right_angle)
	{
		if (sprite->left_angle <= angle && angle <= sprite->right_angle)
			return (true);
	}
	else
	{
		if (sprite->left_angle <= angle || angle <= sprite->right_angle)
			return (true);
	}
	return (false);
}

void	ft_draw_sprite(t_info *info, t_sprite *sprite)
{
	int	i;

	i = 0;
	sprite->corr_dist = sprite->distance
						* cos(sprite->angle - info->player.rot);
	while (i < info->cub.window_width)
	{
		if (ft_sprite_in_fov(info->rays[i].ray_angle, sprite)
		&& sprite->corr_dist < info->zbuffer[i])
			ft_draw_sprite2(info, sprite, i);
		i++;
	}
}

void	ft_render_sprite(t_info *info)
{
	t_list		*lst_p;
	t_sprite	*sprite;

	ft_sort_sprite(info->cub.lists);
	lst_p = info->cub.lists;
	while (lst_p != NULL)
	{
		sprite = lst_p->content;
		ft_draw_sprite(info, sprite);
		lst_p = lst_p->next;
	}
}

double	ft_sprite_rat_x(t_ray ray, t_sprite *sprite)
{
	double	size;
	double	result;

	if (sprite->left_angle > sprite->right_angle)
	{
		size = (TWO_PI - sprite->left_angle) + sprite->right_angle;
		if (ray.ray_angle < PI)
			result = ((TWO_PI - sprite->left_angle) + ray.ray_angle) / size;
		else
			result = (ray.ray_angle - sprite->left_angle) / size;
	}
	else
	{
		result = (ray.ray_angle - sprite->left_angle)
			/ (sprite->right_angle - sprite->left_angle);
	}
	return (result);
}

void	ft_draw_sprite2(t_info *info, t_sprite *sp, int i)
{
	double	s_size;
	int		s_start;
	double	x_rat;
	double	y_rat;
	int		j;

	s_size = (TILE_SIZE / sp->corr_dist) *
					(info->view.width / 2) / tan(FOV / 2);
	s_start = round((info->view.height / 2) - (s_size / 2));
	x_rat = ft_sprite_rat_x(info->rays[i], sp);
	j = s_start > 0 ? s_start : 0;
	while (j < info->cub.window_height && j < s_size + s_start)
	{
		y_rat = (j - s_start) / s_size;
		if (ft_sprite_tex(info, sp, x_rat, y_rat) != 0x000000)
			my_mlx_pixel_put(&info->view, i, j,
				ft_sprite_tex(info, sp, x_rat, y_rat));
		j++;
	}
}
