/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:25:16 by syoshika          #+#    #+#             */
/*   Updated: 2020/11/13 15:33:10 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_n(const char *str)
{
	unsigned char	*array;
	size_t			i;

	if (str == 0)
		return (0);
	i = 0;
	array = (unsigned char *)str;
	while (array[i] != '\n' && array[i])
		i++;
	if (array[i] == '\n')
		return ((char *)&array[i]);
	return (0);
}

int		ft_buf_to_save(char **save, char *buf, int read_size)
{
	char	*tmp;

	buf[read_size] = '\0';
	if (!*save)
		tmp = ft_strdup_size(buf, read_size);
	else
	{
		tmp = ft_strjoin(*save, buf);
		free(*save);
	}
	*save = tmp;
	if (save == 0)
		return (-1);
	if (ft_find_n(*save))
		return (1);
	return (0);
}

int		ft_line(char **save, char **line)
{
	char	*find_n;
	char	*tmp;

	if (ft_find_n(*save))
	{
		find_n = ft_find_n(*save);
		*line = ft_strdup_size(*save, find_n - *save);
		if (line == 0)
			return (-1);
		tmp = ft_strdup_size(find_n + 1, ft_strlen(find_n + 1));
		if (tmp == 0)
			return (-1);
		free(*save);
		*save = tmp;
		return (1);
	}
	else
	{
		*line = *save;
		*save = 0;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static	char	*save[256];
	char			*buf;
	int				read_size;
	int				flag;

	if (fd < 0 || 255 < fd || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	*line = 0;
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		flag = ft_buf_to_save(&save[fd], buf, read_size);
		if (flag != 0 || read_size <= 0)
			break ;
	}
	free(buf);
	if (read_size < 0 || flag == -1)
		return (-1);
	return (ft_line(&save[fd], line));
}
