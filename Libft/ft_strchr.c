/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:45:18 by syoshika          #+#    #+#             */
/*   Updated: 2020/10/14 12:28:20 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*cast_s;
	char	cast_c;
	int		i;

	i = 0;
	cast_s = (char *)s;
	cast_c = (char)c;
	while (cast_s[i] && cast_s[i] != cast_c)
		i++;
	if (cast_s[i] == 0 && cast_s[i] != cast_c)
		return (0);
	return (&cast_s[i]);
}
