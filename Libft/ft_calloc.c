/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:47:20 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/29 12:37:21 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*array;
	char	*cast_array;
	size_t	i;

	i = 0;
	if (!(array = malloc(size * n)))
		return (0);
	cast_array = (char *)array;
	while (size * n > i)
	{
		cast_array[i] = 0;
		i++;
	}
	return (array);
}
