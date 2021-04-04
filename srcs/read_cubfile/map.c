/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:35:06 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:40:16 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(t_info *info)
{
	int		x;
	int		y;

	y = 0;
	while (info->cub.map[y])
	{
		x = 0;
		while (info->cub.map[y][x])
		{
			if (info->cub.map[y][x] == '2')
				ft_sprite(&info->cub, x, y);
			if (ft_strchr("WESN", info->cub.map[y][x]))
			{
				if (info->player.p_flag)
					ft_error(MULTIPLE_PLAYER);
				ft_player(info, x, y);
			}
			x++;
		}
		y++;
	}
	if (!info->player.p_flag)
		ft_error(NO_PLAYER);
	ft_floodfill(&info->cub, info->player.x, info->player.y);
}

int		ft_spec_map(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("WESN 012\t", line[i]))
			return (INVALID_FORMAT);
		i++;
	}
	if (cub->map_maxcol >= 255 || cub->map_maxrow >= 255)
		ft_error(HUGE_MAP);
	if (!(cub->map[cub->map_maxrow] = ft_strdup(line)))
		return (MALLOC_ERROR);
	cub->map[cub->map_maxrow + 1] = NULL;
	cub->map_maxrow++;
	if ((int)ft_strlen(line) > cub->map_maxcol)
		cub->map_maxcol = (int)ft_strlen(line);
	free(line);
	return (MAP);
}

int		ft_perse_map(int fd, t_cub *cub)
{
	int		gnl;
	int		ret;
	char	*line;

	ret = 0;
	line = NULL;
	while ((gnl = get_next_line(fd, &line)) >= 0)
	{
		if (line[0] == '\0')
		{
			free(line);
			break ;
		}
		ret = ft_spec_map(line, cub);
		if (ret != MAP)
			ft_error(ret);
		if (!gnl)
			break ;
	}
	if (gnl == ERROR)
		ft_error(READ_ERROR);
	ft_re_read_cubfile(fd);
	close(fd);
	return (SUCCESS);
}
