/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_pile_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:30:08 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/30 16:54:15 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Here the a pile size isn't bigger than 3. This function is sorting pile a
*/

void	sort_pile_a(t_pile *a, t_pile *b, t_inf *info)
{
	if (a->head->nbr != info->min && a->head->next->next->nbr == info->max)
	{
		ft_sa(a, 'y');
		ft_print_piles(a, b, info->opt);
	}
	else if (a->head->nbr != info->max && a->head->next->next->nbr == info->min)
	{
		ft_rra(a, 'y');
		ft_print_piles(a, b, info->opt);
	}
	else if (a->head->nbr == info->max && a->head->next->next->nbr != info->min)
	{
		ft_ra(a, 'y');
		ft_print_piles(a, b, info->opt);
	}
	else if (a->head->nbr == info->max && a->head->next->next->nbr == info->min)
	{
		ft_ra(a, 'y');
		ft_print_piles(a, b, info->opt);
		ft_sa(a, 'y');
		ft_print_piles(a, b, info->opt);
	}
}

void	sort_pile_first(t_pile *a, t_pile *b, t_inf *info)
{
	if (a->head->nbr == info->min && a->head->next->next->nbr != info->max)
	{
		ft_rra(a, 'y');
		ft_print_piles(a, b, info->opt);
		ft_sa(a, 'y');
		ft_print_piles(a, b, info->opt);
	}
	else
		sort_pile_a(a, b, info);
}

/*
** function that sort the list if a pile size is bigger than 3.
** the nbrs that are not min/max are pushed to pile b
*/

void	big_pile_algo2(t_pile *a, t_pile *b, t_inf *info, t_nlist *tmp)
{
	while (ft_nlist_size(a->head) >= 4)
	{
		if (tmp->nbr == info->max || tmp->nbr == info->min)
		{
			ft_ra(a, 'y');
			ft_print_piles(a, b, info->opt);
			tmp = a->head;
		}
		if (tmp->nbr != info->max && tmp->nbr != info->min)
		{
			ft_pb(a, b, 'y');
			ft_print_piles(a, b, info->opt);
			tmp = a->head;
		}
	}
	sort_pile_first(a, b, info);
	ft_choose_action_b(a, b, info, ft_nlist_size(b->head));
}

void	push_to_b_loop(t_pile *a, t_pile *b, t_inf *info, int cmp_med)
{
	while ((a->head->nbr == info->min || a->head->nbr == info->max
		|| a->head->nbr > info->med) && (cmp_med = ft_is_rot_med(a, info)) != 0)
	{
		if (cmp_med == -1)
		{
			ft_rra(a, 'y');
			ft_is_print(a, b, info);
		}
		else if (cmp_med == 1)
		{
			ft_ra(a, 'y');
			ft_is_print(a, b, info);
		}
	}
	if (cmp_med != 0)
	{
		ft_pb(a, b, 'y');
		ft_print_piles(a, b, info->opt);
	}
}

void	big_pile_algo(t_pile *a, t_pile *b, t_inf *info, int cmp_med)
{
	int			half;
	t_nlist		*tmp;

	half = (ft_nlist_size(a->head) / 2) + 1;
	while (ft_nlist_size(a->head) > half)
	{
		push_to_b_loop(a, b, info, cmp_med);
	}
	tmp = a->head;
	big_pile_algo2(a, b, info, tmp);
}
