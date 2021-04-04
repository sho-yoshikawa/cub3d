/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:26:25 by syoshika          #+#    #+#             */
/*   Updated: 2021/02/21 19:18:33 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_spec_multi(int spec, t_cub *cub)
{
	if ((spec == R && cub->win_f == true)
	|| (spec == NO && cub->no_path_f == true)
	|| (spec == SO && cub->so_path_f == true)
	|| (spec == WE && cub->we_path_f == true)
	|| (spec == EA && cub->ea_path_f == true)
	|| (spec == S && cub->sp_path_f == true)
	|| (spec == F && cub->f_color_f == true)
	|| (spec == C && cub->c_color_f == true))
		return (ERROR);
	return (SUCCESS);
}

void	ft_check_flag(t_info *info)
{
	if (info->cub.win_f == false || info->cub.no_path_f == false
	|| info->cub.so_path_f == false || info->cub.no_path_f == false
	|| info->cub.we_path_f == false || info->cub.ea_path_f == false
	|| info->cub.sp_path_f == false || info->cub.f_color_f == false
	|| info->cub.c_color_f == false)
		ft_error(LESS_PARAMS);
}
