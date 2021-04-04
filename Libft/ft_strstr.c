/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:29:21 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/08 16:00:49 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	char *dest;
	char *src;

	if (*to_find == 0)
		return ((char *)str);
	while (*str)
	{
		dest = (char *)str;
		src = (char *)to_find;
		while (*src && *dest == *src)
		{
			dest++;
			src++;
		}
		if (*src == 0)
			return ((char *)str);
		str++;
	}
	return (0);
}
