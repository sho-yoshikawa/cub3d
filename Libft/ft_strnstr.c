/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:20:14 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/29 12:51:51 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	if (*to_find == '\0')
		return ((char *)str);
	i = ft_strlen(to_find);
	while (*str != '\0' && n >= i)
	{
		if (ft_memcmp(str, to_find, i) == 0)
			return ((char *)str);
		str++;
		n--;
	}
	return (0);
}
