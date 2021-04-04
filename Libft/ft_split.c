/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:53:58 by syoshika          #+#    #+#             */
/*   Updated: 2021/01/29 14:57:26 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*array_free(char **array, size_t len)
{
	while (len)
	{
		free(array[len]);
		len--;
	}
	free(array);
	return (0);
}

static size_t	ft_array_length(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (s[i] && s[i] != c)
		count++;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_str_length(char const *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	size_t	array_len;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (0);
	array_len = ft_array_length(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (array_len + 1))))
		return (0);
	i = 0;
	while (i < array_len)
	{
		while (*s == c)
			s++;
		str_len = ft_str_length(s, c);
		if (!(array[i] = malloc(sizeof(char) * (str_len + 1))))
			return (array_free(array, i));
		ft_strlcpy(array[i], (char *)s, str_len + 1);
		s += str_len;
		i++;
	}
	array[i] = 0;
	return (array);
}
