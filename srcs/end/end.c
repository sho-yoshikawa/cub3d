/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:51:01 by syoshika          #+#    #+#             */
/*   Updated: 2021/02/14 14:51:11 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_end(t_info *info)
{
	mlx_destroy_image(info->mlx, info->view.img_ptr);
	exit(EXIT_SUCCESS);
}
