/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:09:08 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:15:08 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi_for_fc(char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	if (str[i] == '0' && str[i + 1] != '\0')
		return (ERROR);
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (!(0 <= num && num <= 255))
		return (ERROR);
	return (SUCCESS);
}

int		ft_atoi_for_r(char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	if (str[i] == '0' && str[i + 1] == '\0')
		return (ERROR);
	if (str[i] == '0' && str[i + 1] != '\0')
		return (ERROR);
	while (1)
	{
		if (ft_isdigit(str[i]))
		{
			num = num * 10 + str[i] - '0';
			i++;
		}
		else
			return (ERROR);
		if (str[i] == '\0')
			break ;
	}
	return (SUCCESS);
}
