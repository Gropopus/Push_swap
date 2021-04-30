/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:38:23 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/30 12:36:02 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_loop_action(t_pile *pile, int nb_action, int action)
{
	if (nb_action > 0)
	{
		while (nb_action > 0)
		{
			if (action == 1)
				ft_ra(pile, 'y');
			else if (action == 2)
				ft_rb(pile, 'y');
			else if (action == 3)
				ft_rra(pile, 'y');
			else if (action == 4)
				ft_rrb(pile, 'y');
			nb_action--;
		}
	}
}

void	ft_do_action_both(t_pile *a, t_pile *b, t_inf *info)
{
	if (info->s_test > 0)
	{
		while (info->f_test > 0 && info->s_test > 0)
		{
			ft_rr(a, b, 'y');
			info->f_test -= 1;
			info->s_test -= 1;
		}
		ft_loop_action(a, info->f_test, 1);
		ft_loop_action(b, info->s_test, 2);
	}
	else
	{
		info->s_test = -info->s_test;
		ft_loop_action(a, info->f_test, 1);
		ft_loop_action(b, info->s_test, 4);
	}
}

void	ft_do_action(t_pile *a, t_pile *b, t_inf *info)
{
	info->f_test = -info->f_test;
	if (info->s_test > 0)
	{
		ft_loop_action(b, info->s_test, 2);
		ft_loop_action(a, info->f_test, 3);
	}
	else
	{
		info->s_test = -info->s_test;
		while (info->f_test > 0 && info->s_test > 0)
		{
			ft_rrr(a, b, 'y');
			info->f_test -= 1;
			info->s_test -= 1;
		}
		ft_loop_action(a, info->f_test, 3);
		ft_loop_action(b, info->s_test, 4);
	}
}

/*
** Function that manange actions according to the test_action results til
** the b pile is empty
*/

void	ft_choose_action(t_pile *a, t_pile *b, t_inf *info)
{
	int i;

	i = ft_nlist_size(b->head);
	while (i > 0)
	{
		info->f_test = ft_test_actions(a, b, info, 0);
		if (info->f_test < 0)
			ft_do_action(a, b, info);
		else if (info->f_test > 0)
			ft_do_action_both(a, b, info);
		else
		{
			if (info->s_test > 0)
				ft_loop_action(b, info->s_test, 2);
			else
				ft_loop_action(b, -info->s_test, 4);
		}
		ft_pa(a, b, 'y');
		i--;
	}
	last_sort(a, info, 0);
}
