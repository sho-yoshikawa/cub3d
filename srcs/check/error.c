/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:00:10 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 13:29:59 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(int ret)
{
	const char	err_msg[][256] = {
		{"Cannot read in cubfile.\n"},
		{"Something wrong in cub3D file.\n"},
		{"Malloc error happenned.\n"},
		{"Cannot open file.\n"},
		{"Arguments are wrong.\n"},
		{"Cubfile is invalid.\n"},
		{"Invalid format.\n"},
		{"Invalid resolution.\n"},
		{"Invalid filepath.\n"},
		{"Not enough info in cubfile.\n"},
		{"No players are in map.\n"},
		{"Identifier is duplicated.\n"},
		{"2 or more players exist.\n"},
		{"Map is not closed.\n"},
		{"Map is too much huge.\n"},
		{"Missing some parameters in cubfile.\n"},
		{"Map is not selected.\n"},
		{"Invalid --save flag.\n"},
		{"Broken xpmfile detected.\n"},
		{"Something is under map info.\n"}
	};

	printf("Error\n%s", err_msg[ret]);
	exit(EXIT_FAILURE);
}
