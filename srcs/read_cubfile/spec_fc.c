/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:56:10 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:48:45 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		ft_check_color(char **strs)
{
	int i;

	if (ft_strs_length(strs) != 3)
		return (ERROR);
	i = 0;
	while (i < 3)
	{
		if (!strs[i] || !ft_isdigit_char(strs[i])
		|| (ft_atoi_for_fc(strs[i]) == ERROR))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	ft_check_digit_fc(int rgb[], char **strs)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(strs[i]);
		if (!(0 <= rgb[i] && rgb[i] <= 255))
		{
			ft_all_free_split(strs);
			ft_error(INVALID_FORMAT);
		}
		i++;
	}
}

int		ft_spec_fc(char *line, int spec, t_cub *cub)
{
	char	**strs;
	int		rgb[3];
	char	*tmp;

	if (ft_check_comma(line) == ERROR)
		return (INVALID_FORMAT);
	if (!(strs = ft_split(line, ',')))
		return (MALLOC_ERROR);
	tmp = line - 2;
	free(tmp);
	if (ft_check_color(strs) == ERROR)
	{
		ft_all_free_split(strs);
		return (INVALID_FORMAT);
	}
	ft_check_digit_fc(rgb, strs);
	if (spec == F)
		cub->f_color = ft_create_rgb(rgb[0], rgb[1], rgb[2]);
	if (spec == C)
		cub->c_color = ft_create_rgb(rgb[0], rgb[1], rgb[2]);
	ft_set_spec_flag(spec, cub);
	ft_all_free_split(strs);
	return (SUCCESS);
}
