/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:39:44 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/28 18:26:58 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*cast_s1 != *cast_s2)
			return (*cast_s1 - *cast_s2);
		if (*cast_s1 == '\0')
			return (0);
		cast_s1++;
		cast_s2++;
		n--;
	}
	return (0);
}
