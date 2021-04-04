/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:54:39 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/16 11:54:41 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*((unsigned int *)dst) = color;
}

int		get_color(char c, int trgb)
{
	if (c == 't')
		return ((trgb & (0xFF << 24)) >> 24);
	if (c == 'r')
		return ((trgb & (0xFF << 16)) >> 16);
	if (c == 'g')
		return ((trgb & (0xFF << 8)) >> 8);
	if (c == 'b')
		return (trgb & 0xFF);
	return (ERROR);
}

double	ft_fix_angle(double rot)
{
	if (rot > TWO_PI)
		rot -= TWO_PI;
	if (rot < 0)
		rot = rot + TWO_PI;
	return (rot);
}
