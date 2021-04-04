/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:41:19 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/23 13:35:11 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cast_s;
	unsigned char	cast_c;
	size_t			i;

	cast_s = (unsigned char *)s;
	cast_c = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (cast_s[i] == cast_c)
			return ((void *)&s[i]);
		i++;
		n--;
	}
	return (0);
}
