/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:47:40 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:16:42 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite(t_cub *cub, int x, int y)
{
	t_list		*list;
	t_sprite	*sprite;

	if (!(sprite = malloc(sizeof(t_sprite))))
		ft_error(MALLOC_ERROR);
	sprite->x = x;
	sprite->y = y;
	if (!(list = ft_lstnew(sprite)))
		ft_error(MALLOC_ERROR);
	ft_lstadd_back(&cub->lists, list);
	cub->map[y][x] = '0';
}

void	ft_sprite_calc(t_list *lists, t_pl player)
{
	t_sprite	*sp;
	double		sprite_pos1;
	double		sprite_pos2;

	while (lists)
	{
		sp = (t_sprite *)lists->content;
		sp->distance = DIST(sp->x, sp->y, player.x, player.y);
		sp->angle = ft_fix_angle(atan2(sp->y - player.y, sp->x - player.x));
		sprite_pos1 = sp->x + cos(sp->angle + HALF_PI) * TILE_SIZE / 2;
		sprite_pos2 = sp->y + sin(sp->angle + HALF_PI) * TILE_SIZE / 2;
		sp->right_angle = ft_fix_angle(
			atan2(sprite_pos2 - player.y, sprite_pos1 - player.x));
		sprite_pos1 = sp->x + cos(sp->angle - HALF_PI) * TILE_SIZE / 2;
		sprite_pos2 = sp->y + sin(sp->angle - HALF_PI) * TILE_SIZE / 2;
		sp->left_angle = ft_fix_angle(
			atan2(sprite_pos2 - player.y, sprite_pos1 - player.x));
		lists = lists->next;
	}
}
