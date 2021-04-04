/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:01:42 by syoshika          #+#    #+#             */
/*   Updated: 2020/11/19 18:32:07 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_judge_num(long num)
{
	if (num > INT_MAX)
		return (-1);
	else if (num < INT_MIN)
		return (0);
	else
		return ((int)num);
}

int			ft_atoi(const char *str)
{
	long	num;
	int		i;
	long	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	num *= sign;
	return (ft_judge_num(num));
}
