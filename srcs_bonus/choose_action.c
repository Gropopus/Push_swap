/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:38:23 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/30 16:47:47 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_loop_action(t_pile *pile, t_pile *other, int nb_action, t_inf *info)
{
	if (nb_action > 0)
		while (nb_action > 0)
		{
			if (info->flag == 1)
			{
				ft_ra(pile, 'y');
				ft_print_piles(pile, other, info->opt);
			}
			else if (info->flag == 2)
			{
				ft_rb(pile, 'y');
				ft_print_piles(other, pile, info->opt);
			}
			else if (info->flag == 3)
			{
				ft_rra(pile, 'y');
				ft_print_piles(pile, other, info->opt);
			}
			else if (info->flag == 4)
			{
				ft_rrb(pile, 'y');
				ft_print_piles(other, pile, info->opt);
			}
			nb_action--;
		}
}

void	ft_do_action_both(t_pile *a, t_pile *b, t_inf *info)
{
	if (info->s_test > 0)
	{
		while (info->f_test > 0 && info->s_test > 0)
		{
			ft_rr(a, b, 'y');
			ft_print_piles(a, b, info->opt);
			info->f_test -= 1;
			info->s_test -= 1;
		}
		info->flag = 1;
		ft_loop_action(a, b, info->f_test, info);
		info->flag = 2;
		ft_loop_action(b, a, info->s_test, info);
	}
	else
	{
		info->s_test = -info->s_test;
		info->flag = 1;
		ft_loop_action(a, b, info->f_test, info);
		info->flag = 4;
		ft_loop_action(b, a, info->s_test, info);
	}
}

void	ft_do_action(t_pile *a, t_pile *b, t_inf *info)
{
	info->f_test = -info->f_test;
	if (info->s_test > 0)
	{
		info->flag = 2;
		ft_loop_action(b, a, info->s_test, info);
		info->flag = 3;
		ft_loop_action(a, b, info->f_test, info);
	}
	else
	{
		info->s_test = -info->s_test;
		while (info->f_test > 0 && info->s_test > 0)
		{
			ft_rrr(a, b, 'y');
			ft_print_piles(a, b, info->opt);
			info->f_test -= 1;
			info->s_test -= 1;
		}
		info->flag = 3;
		ft_loop_action(a, b, info->f_test, info);
		info->flag = 4;
		ft_loop_action(b, a, info->s_test, info);
	}
}

/*
** Function that manange actions according to the test_action results til
** the b pile is empty
*/

void	ft_choose_action_b(t_pile *a, t_pile *b, t_inf *info, int i)
{
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
			{
				info->flag = 2;
				ft_loop_action(b, a, info->s_test, info);
			}
			else
			{
				info->flag = 4;
				ft_loop_action(b, a, -info->s_test, info);
			}
		}
		ft_pa(a, b, 'y');
		ft_print_piles(a, b, info->opt);
		i--;
	}
	ft_last_sort_bonus(a, info, 0);
}
