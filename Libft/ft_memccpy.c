/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:49:55 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/15 17:19:23 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;
	size_t			i;
	unsigned char	cast_c;

	cast_c = (unsigned char)c;
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	i = 0;
	if (cast_dest == 0 && cast_src == 0)
		return (0);
	while (n > 0)
	{
		cast_dest[i] = cast_src[i];
		if (cast_dest[i] == cast_c)
		{
			i++;
			return (&cast_dest[i]);
		}
		i++;
		n--;
	}
	return (0);
}
