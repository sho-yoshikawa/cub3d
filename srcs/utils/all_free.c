/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:46:18 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:15:58 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_all_free_split(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
		i++;
	while (i + 1)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
}
