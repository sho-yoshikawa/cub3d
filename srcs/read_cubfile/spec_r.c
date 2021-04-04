/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:09:07 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:49:45 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_spec_r(char *line, t_cub *cub)
{
	int		i;
	char	**strs;
	char	*tmp;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ' ' || ft_isdigit(line[i])))
			return (INVALID_FORMAT);
		i++;
	}
	if (!(strs = ft_split(line, ' ')))
		return (MALLOC_ERROR);
	tmp = line - 2;
	free(tmp);
	if (ft_strs_length(strs) != 2
			|| (ft_atoi_for_r(strs[0]) == ERROR)
			|| (ft_atoi_for_r(strs[1]) == ERROR))
		return (INVALID_FORMAT);
	cub->window_width = ft_atoi(strs[0]);
	cub->window_height = ft_atoi(strs[1]);
	ft_all_free_split(strs);
	cub->win_f = true;
	return (SUCCESS);
}

void	ft_sizecheck_r(t_info *info)
{
	int	width;
	int	height;

	mlx_get_screen_size(info->mlx, &width, &height);
	if (info->save_flag)
	{
		if (info->cub.window_width > 16384)
			info->cub.window_width = width;
		if (info->cub.window_height > 16384)
			info->cub.window_height = height;
	}
	else
	{
		if (info->cub.window_width > width)
			info->cub.window_width = width;
		if (info->cub.window_height > height)
			info->cub.window_height = height;
	}
}
