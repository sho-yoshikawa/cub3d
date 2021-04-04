/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:59:13 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/23 15:00:22 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*cast_s;
	char	cast_c;

	cast_s = (char *)s;
	cast_c = (char)c;
	len = ft_strlen(cast_s);
	while (len > 0 && cast_s[len] != cast_c)
		len--;
	if (cast_s[len] == cast_c)
		return (&cast_s[len]);
	return (0);
}
