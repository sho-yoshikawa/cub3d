/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:03:15 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:35:58 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_floodfill(t_cub *cub, int x, int y)
{
	if (x < 0 || y < 0 || !cub->map[y] || ft_strchr("*1", cub->map[y][x]))
		return ;
	if (x == 0 || y == 0 || !cub->map[y + 1] || !cub->map[y][x + 1])
		ft_error(MAP_ISNT_CLOSED);
	cub->map[y][x] = '*';
	ft_floodfill(cub, x + 1, y);
	ft_floodfill(cub, x, y + 1);
	ft_floodfill(cub, x - 1, y);
	ft_floodfill(cub, x, y - 1);
}
