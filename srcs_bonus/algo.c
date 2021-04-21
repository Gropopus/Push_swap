/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:01:03 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:30:20 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b_pile(t_pile *b, t_inf *info)
{
	while (!ft_is_rsorted(b->head))
	{
		if (b->head->nbr == info->min)
			ft_rb(b, 'y');
		else
		{
			if (((b->head && b->head->next
				&& b->head->nbr > b->head->next->nbr)
				|| (b->head && b->head->nbr == info->min))
				&& !ft_is_rsorted(b->head))
				ft_rb(b, 'y');
			if (b->head && b->head && b->head->next
				&& b->head->nbr < b->head->next->nbr
				&& !ft_is_rsorted(b->head))
				ft_sb(b, 'y');
		}
	}
}

void	sort_a_pile_next(t_pile *a, t_pile *b, t_inf *info)
{
	if ((a->head->nbr < a->head->next->nbr && a->head->nbr >= info->med)
		|| a->head->nbr == info->max)
	{
		if (((b->head && b->head->next
			&& b->head->nbr > b->head->next->nbr)
			|| (b->head && b->head->nbr == info->min))
			&& !ft_is_rsorted(b->head))
			ft_rr(a, b, 'y');
		else
			ft_ra(a, 'y');
	}
	if (a->head->nbr < info->med)
		ft_pb(a, b, 'y');
}

void	sort_a_pile(t_pile *a, t_pile *b, t_inf *info)
{
	if (a->head->nbr > a->head->next->nbr)
	{
		if (b->head && b->head && b->head->next
			&& b->head->nbr < b->head->next->nbr && !ft_is_rsorted(b->head))
			ft_ss(a, b, 'y');
		else if (a->head->nbr == info->max)
			ft_ra(a, 'y');
		else
			ft_sa(a, 'y');
	}
	else
		sort_a_pile_next(a, b, info);
}

void	small_pile_algo(t_pile *a, t_pile *b, t_inf *info)
{
	while (!ft_is_sorted(a->head))
		sort_a_pile(a, b, info);
	if (b->head)
		sort_b_pile(b, info);
	while (b->head)
		ft_pa(a, b, 'y');
	if (!ft_is_sorted(a->head))
		small_pile_algo(a, b, info);
}

void	algo_manager(t_pile *a, t_pile *b, t_inf *info)
{
	if (info->size < 7 || (info->size > 6
		&& ft_is_sorted(a->head->next->next) == 1))
		small_pile_algo(a, b, info);
	else
		big_pile_algo(a, b, info, 2);
}
