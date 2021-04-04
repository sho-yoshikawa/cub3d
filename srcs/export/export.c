/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:06:08 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:22:11 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bmp_data(t_img *img, int width, int height, int fd)
{
	int		i;
	char	*color;

	height--;
	while (height >= 0)
	{
		i = 0;
		while (i < width)
		{
			color = img->addr + height * img->len + i * (img->bpp / 8);
			write(fd, color, 3);
			i++;
		}
		i = 4 - ((width * 3) % 4);
		if (i != 4)
		{
			while (i > 0)
			{
				write(fd, "0", 1);
				i--;
			}
		}
		height--;
	}
}

void	ft_info_header(int fd, t_img view)
{
	unsigned char	header[40];

	ft_bzero(header, 40);
	header[0] = 40;
	header[4] = (unsigned char)(view.width % 256);
	header[5] = (unsigned char)(view.width / 256 % 256);
	header[6] = (unsigned char)(view.width / 256 / 256 % 256);
	header[7] = (unsigned char)(view.width / 256 / 256 / 256);
	header[8] = (unsigned char)(view.height % 256);
	header[9] = (unsigned char)(view.height / 256 % 256);
	header[10] = (unsigned char)(view.height / 256 / 256 % 256);
	header[11] = (unsigned char)(view.height / 256 / 256 / 256);
	header[12] = 1;
	header[14] = 24;
	write(fd, header, 40);
}

void	ft_file_header(int fd, t_img view)
{
	int				filesize;
	int				padding;
	unsigned char	header[14];

	padding = 4 - ((view.width * 3) % 4);
	filesize = (((view.width * 3) + padding) * view.height) + 54;
	ft_bzero(header, 14);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(filesize % 256);
	header[3] = (unsigned char)(filesize / 256 % 256);
	header[4] = (unsigned char)(filesize / 256 / 256 % 256);
	header[5] = (unsigned char)(filesize / 256 / 256 / 256);
	header[10] = 54;
	write(fd, header, 14);
}

void	ft_export(t_info *info)
{
	int	fd;

	ft_sprite_calc(info->cub.lists, info->player);
	ft_raycasting(info);
	ft_render_wall(info);
	ft_render_sprite(info);
	fd = open("./bmpfile/export.bmp", O_CREAT | O_WRONLY,
										S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == ERROR)
		ft_error(OPEN_ERROR);
	ft_file_header(fd, info->view);
	ft_info_header(fd, info->view);
	ft_bmp_data(&info->view, info->view.width, info->view.height, fd);
	close(fd);
	ft_end(info);
}
