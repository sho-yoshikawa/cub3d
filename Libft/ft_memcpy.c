/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:07:11 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/26 14:08:09 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;
	size_t			i;

	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		cast_dest[i] = cast_src[i];
		i++;
		n--;
	}
	return (dest);
}
