/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:08:29 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/26 14:10:30 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *array, int charset, size_t n)
{
	unsigned char	*cast_array;
	int				i;

	i = 0;
	cast_array = array;
	while (n > 0)
	{
		cast_array[i] = (unsigned char)charset;
		i++;
		n--;
	}
	return (array);
}
