/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:25:11 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/26 17:45:33 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;
	size_t			i;

	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	i = 0;
	if (cast_dest == 0 && cast_src == 0)
		return (dest);
	if (cast_dest > cast_src)
		while (i++ < len)
			cast_dest[len - i] = cast_src[len - i];
	else
		while (len > 0)
		{
			*cast_dest++ = *cast_src++;
			len--;
		}
	return (dest);
}
