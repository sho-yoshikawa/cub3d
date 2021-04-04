/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:53:28 by syoshika          #+#    #+#             */
/*   Updated: 2021/02/09 13:31:06 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_re_read_cubfile(int fd)
{
	char	*line;

	get_next_line(fd, &line);
	if (*line)
	{
		free(line);
		ft_error(UNDER_MAP_INFO);
	}
	free(line);
}

int		ft_spec_branch(char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (R);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (NO);
	if (ft_strncmp(line, "SO ", 2) == 0)
		return (SO);
	if (ft_strncmp(line, "WE ", 2) == 0)
		return (WE);
	if (ft_strncmp(line, "EA ", 2) == 0)
		return (EA);
	if (ft_strncmp(line, "S ", 2) == 0)
		return (S);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (F);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (C);
	return (MAP);
}

int		ft_perse_line(char *line, t_cub *cub)
{
	int		spec;

	if (*line == '\0')
	{
		free(line);
		return (SUCCESS);
	}
	spec = ft_spec_branch(line);
	if (ft_spec_multi(spec, cub) == ERROR)
		ft_error(MULTIPLE_ID);
	if (spec == R)
		return (ft_spec_r(line + 2, cub));
	if (NO <= spec && spec <= S)
		return (ft_spec_path(line + 2, spec, cub));
	if (spec == F || spec == C)
		return (ft_spec_fc(line + 2, spec, cub));
	if (spec == MAP)
		return (ft_spec_map(line, cub));
	return (ERROR);
}

int		ft_read_cub(char *argv, t_cub *cub)
{
	char	*line;
	int		gnl;
	int		ret;
	int		fd;

	ret = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	while (ret != MAP && (gnl = get_next_line(fd, &line)) >= 0)
	{
		if (!gnl)
			ft_error(NO_INFO_FOUND);
		ret = ft_perse_line(line, cub);
		if (ret != SUCCESS && ret != MAP)
			ft_error(ret);
	}
	if (gnl == ERROR)
		ft_error(READ_ERROR);
	ft_check_path(cub);
	return (ft_perse_map(fd, cub));
}
