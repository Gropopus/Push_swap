/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_action2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:50:12 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/30 16:50:17 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Final function of the big pile sorting algo.
** This function put the min value to the first posistion.
*/

int		ft_find_min_index(t_pile *a, t_inf *info)
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

void	ft_last_sort_bonus(t_pile *a, t_inf *info, int i)
{
	int		min_index;

	min_index = ft_find_min_index(a, info);
	if (min_index < ft_nlist_size(a->head) / 2)
		while (i < min_index)
		{
			ft_ra(a, 'y');
			ft_print_piles(a, NULL, info->opt);
			i++;
		}
	else
		while (i < ft_nlist_size(a->head) - min_index)
		{
			ft_rra(a, 'y');
			ft_print_piles(a, NULL, info->opt);
			i++;
		}
}
