/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:29:04 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/12 15:56:57 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_is_sorted(t_nlist *nlist)
{
	if (nlist == NULL)
		return (0);
	else
	{
		while (nlist->next)
		{
			if (nlist->nbr > nlist->next->nbr)
				return (0);
			nlist = nlist->next;
		}
		return (1);
	}
}

int			ft_is_rsorted(t_nlist *nlist)
{
	if (nlist == NULL)
		return (0);
	else
	{
		while (nlist->next)
		{
			if (nlist->nbr < nlist->next->nbr)
				return (0);
			nlist = nlist->next;
		}
		return (1);
	}
}

int			ft_find_min_index(t_pile *a, t_inf *info)
{
	t_nlist	*tmp;
	int		min_index;
	int		i;

	i = 0;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->nbr == info->min)
			min_index = i;
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}
