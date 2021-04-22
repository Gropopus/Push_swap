/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_action2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:56:47 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/22 12:29:32 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_push(t_pile *a, t_pile *b, t_inf *info, int val)
{
	if (val != 0)
	{
		ft_pb(a, b, 'y');
		ft_print_piles(a, b, info->opt);
	}
}

void	push_to_b_loop(t_pile *a, t_pile *b, t_inf *info, int val)
{
	while (a->head->nbr == info->min || a->head->nbr == info->max
	|| a->head->nbr > info->med)
	{
		val = ft_is_rot_med(a, info);
		if (val == 1)
		{
			ft_ra(a, 'y');
			if (ft_nlist_size(b->head) > 0)
				ft_print_piles(a, b, info->opt);
			else
				ft_print_piles(a, NULL, info->opt);
		}
		else if (val == -1)
		{
			ft_rra(a, 'y');
			if (ft_nlist_size(b->head) > 0)
				ft_print_piles(a, b, info->opt);
			else
				ft_print_piles(a, NULL, info->opt);
		}
		else
			break ;
	}
	b_push(a, b, info, val);
}

void	ft_choose_action5(t_pile *a, t_pile *b, t_inf *info, int choice)
{
	if (choice == 1)
	{
		while (info->f_test > 0 && info->s_test > 0)
		{
			ft_rrr(a, b, 'y');
			ft_print_piles(a, b, info->opt);
			info->f_test -= 1;
			info->s_test -= 1;
		}
	}
}
