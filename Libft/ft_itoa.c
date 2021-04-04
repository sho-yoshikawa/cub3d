/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:57:33 by syoshika          #+#    #+#             */
/*   Updated: 2020/11/19 18:32:05 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_which_sign(long n)
{
	int		length;

	if (n > 0)
		length = 0;
	else
		length = 1;
	return (length);
}

int			ft_digit_count(int n)
{
	int		length;

	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char		*ft_itoa(int nbr)
{
	long	n;
	size_t	length;
	char	*array;

	n = (long)nbr;
	length = ft_which_sign(n);
	length += ft_digit_count(n);
	n = (n > 0) ? n : (n * -1);
	if (!(array = (char *)malloc(sizeof(char) * length + 1)))
		return (0);
	if (n == 0)
		*array = '0';
	array[length] = '\0';
	length -= 1;
	while (n > 0)
	{
		array[length] = n % 10 + '0';
		n /= 10;
		length--;
	}
	if (array[1] != '\0' && length == 0)
		*array = '-';
	return (array);
}
