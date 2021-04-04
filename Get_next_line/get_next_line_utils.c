/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:11:14 by syoshika          #+#    #+#             */
/*   Updated: 2020/11/12 18:24:05 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_size(char *str, int size)
{
	char	*array;
	size_t	i;
	int		length;

	length = (int)ft_strlen(str) >= size ? size : (int)ft_strlen(str);
	i = 0;
	if (!(array = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	while (str[i] && size > 0)
	{
		array[i] = str[i];
		i++;
		size--;
	}
	array[i] = '\0';
	return (array);
}
