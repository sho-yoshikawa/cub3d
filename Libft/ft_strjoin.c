/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:45:45 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/14 16:29:16 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		length;
	char	*array;

	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	if (!(array = (char *)malloc(sizeof(char) * length + 1)))
		return (0);
	while (*s1)
		array[i++] = *s1++;
	while (*s2)
		array[i++] = *s2++;
	array[i] = '\0';
	return (array);
}
