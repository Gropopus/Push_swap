/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_pile_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:30:08 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/20 15:59:52 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Final function of the big pile sorting algo.
** This function put the min value to the first posistion.
*/

void	last_sort(t_pile *a, t_inf *info, int i)
{
	t_nlist	*tmp;
	int		min_index;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->nbr == info->min)
			min_index = i;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	if (min_index < ft_nlist_size(a->head) / 2)
		while (i < min_index)
		{
			ft_ra(a, 'y');
			i++;
		}
	else
		while (i < ft_nlist_size(a->head) - min_index)
		{
			ft_rra(a, 'y');
			i++;
		}
}

/*
** Here the a pile size isn't bigger than 3. This function is sorting pile a
*/

void	sort_pile_a(t_pile *a, t_inf *info)
{
	if (a->head->nbr != info->min && a->head->next->next->nbr == info->max)
		ft_sa(a, 'y');
	else if (a->head->nbr != info->max && a->head->next->next->nbr == info->min)
		ft_rra(a, 'y');
	else if (a->head->nbr == info->max && a->head->next->next->nbr != info->min)
		ft_ra(a, 'y');
	else if (a->head->nbr == info->max && a->head->next->next->nbr == info->min)
	{
		ft_ra(a, 'y');
		ft_sa(a, 'y');
	}
}

/*
** function that sort the list if a pile size is bigger than 3.
** the nbrs that are not min/max are pushed to pile b
*/

void	big_pile_algo2(t_pile *a, t_pile *b, t_inf *info)
{
	t_nlist	*tmp;

	tmp = a->head;
	while (ft_nlist_size(a->head) > 3)
	{
		if (tmp->nbr == info->min || tmp->nbr == info->max)
		{
			ft_ra(a, 'y');
			tmp = a->head;
		}
		if (tmp->nbr != info->min && tmp->nbr != info->max)
		{
			ft_pb(a, b, 'y');
			tmp = a->head;
		}
	}
	if (a->head->nbr == info->min && a->head->next->next->nbr != info->max)
	{
		ft_rra(a, 'y');
		ft_sa(a, 'y');
	}
	else
		sort_pile_a(a, info);
	ft_choose_action(a, b, info);
}

/*
** function that sorts each number of pile a bigger than the med or the
** min value. if the nbr is located at the top of the med value ->ra else ->rra
** break if the value is med or < than med.
** if the a pile is smaller than 4 the pb.
*/

void	big_pile_algo(t_pile *a, t_pile *b, t_inf *info, int val)
{
	int		size;

	size = ft_nlist_size(a->head);
	while (ft_nlist_size(a->head) > (int)(size / 2) + 1)
	{
		while (a->head->nbr == info->min || a->head->nbr == info->max
		|| a->head->nbr > info->med)
		{
			val = ft_is_rot_med(a, info);
			if (val == 1)
				ft_ra(a, 'y');
			else if (val == -1)
				ft_rra(a, 'y');
			else
				break ;
		}
		if (val != 0)
			ft_pb(a, b, 'y');
	}
	big_pile_algo2(a, b, info);
}
