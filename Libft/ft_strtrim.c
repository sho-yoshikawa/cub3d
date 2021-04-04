/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:45:25 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/23 15:08:45 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char c, char const *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	length;
	char			*array_start;
	char			*array_end;
	char			*array;

	i = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while (s1[i] && ft_charset(s1[i], set))
		i++;
	array_start = (char *)&s1[i];
	i = ft_strlen(s1) - 1;
	if (i >= 0)
		while (s1[i] && ft_charset(s1[i], set))
			i--;
	array_end = (char *)&s1[i];
	length = array_end - array_start + 2;
	if (!(array = (char *)malloc(sizeof(char) * length)))
		return (0);
	ft_strlcpy(array, array_start, length);
	return (array);
}
