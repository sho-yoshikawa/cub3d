/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:13:45 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/29 16:30:06 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s == 0)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (start >= ft_strlen(s))
	{
		str[i] = 0;
		return (str);
	}
	while (len > 0)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
