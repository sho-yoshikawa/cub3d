/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:12:53 by syoshika          #+#    #+#             */
/*   Updated: 2021/03/29 17:52:51 by syoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_long_dist_sp(t_list *lists)
{
	double		dist;
	t_list		*tmp;
	t_sprite	*content;

	dist = 0.0;
	tmp = lists;
	while (lists != NULL)
	{
		content = lists->content;
		if (content->distance > dist)
			dist = content->distance;
		lists = lists->next;
	}
	while (tmp != NULL)
	{
		content = tmp->content;
		if (content->distance == dist)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_sort_sprite(t_list *items)
{
	t_list		*lst_p;
	t_sprite	*content;

	while (items != NULL)
	{
		lst_p = ft_long_dist_sp(items);
		content = items->content;
		items->content = lst_p->content;
		lst_p->content = content;
		items = items->next;
	}
}
