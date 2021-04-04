/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:41:02 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:37:30 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_path(t_cub *cub)
{
	int		fd;
	int		i;
	char	*paths[6];

	paths[0] = cub->no_path;
	paths[1] = cub->so_path;
	paths[2] = cub->we_path;
	paths[3] = cub->ea_path;
	paths[4] = cub->sp_path;
	i = 0;
	while (i < 5)
	{
		if (((fd = open(paths[i], O_RDONLY)) == ERROR))
			ft_error(INVALID_PATH);
		close(fd);
		i++;
	}
}

int		ft_spec_path(char *line, int spec, t_cub *cub)
{
	char	*path;
	char	*tmp;

	if (!(path = ft_strtrim(line, " ")))
		return (MALLOC_ERROR);
	if (spec == NO)
		cub->no_path = path;
	if (spec == SO)
		cub->so_path = path;
	if (spec == WE)
		cub->we_path = path;
	if (spec == EA)
		cub->ea_path = path;
	if (spec == S)
		cub->sp_path = path;
	tmp = line - 2;
	free(tmp);
	ft_set_spec_flag(spec, cub);
	return (SUCCESS);
}

int		ft_set_spec_flag(int spec, t_cub *cub)
{
	if (spec == NO)
		cub->no_path_f = true;
	if (spec == SO)
		cub->so_path_f = true;
	if (spec == WE)
		cub->we_path_f = true;
	if (spec == EA)
		cub->ea_path_f = true;
	if (spec == S)
		cub->sp_path_f = true;
	if (spec == F)
		cub->f_color_f = true;
	if (spec == C)
		cub->c_color_f = true;
	return (ERROR);
}
