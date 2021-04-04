/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:45:41 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/23 13:44:14 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;
	size_t			i;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((cast_s1[i] == cast_s2[i]) && n > 1)
	{
		i++;
		n--;
	}
	return (cast_s1[i] - cast_s2[i]);
}
