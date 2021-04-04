/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:50:09 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:23:52 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cubfile_fmt(char *path)
{
	size_t	len;
	char	*trim_path;

	if (!path)
		return (ERROR);
	len = ft_strlen(path);
	trim_path = ft_substr(path, len - 5, 5);
	if ((ft_strncmp(trim_path + 1, ".cub", 5) == 0)
	&& ft_strncmp(trim_path, "/.cub", 6) != 0)
	{
		free(trim_path);
		return (SUCCESS);
	}
	free(trim_path);
	return (ERROR);
}

void	ft_argment_error(int argc, char **argv, t_info *info)
{
	int fd;

	if (!(argc == 2 || argc == 3))
		ft_error(INVALID_ARG);
	if (ft_cubfile_fmt(argv[1]) == ERROR)
		ft_error(INVALID_CUBFILE);
	if ((fd = open(argv[1], O_RDONLY)) == ERROR)
		ft_error(OPEN_ERROR);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7) == 0)
			info->save_flag = true;
		else
			ft_error(NOT_SAVE_F);
	}
	close(fd);
}
