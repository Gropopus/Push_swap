/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:38:23 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:18:03 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_choose_action4(t_pile *a, t_pile *b, t_inf *info, int choice)
{
	info->s_test = -info->s_test;
	if (choice == 1)
	{
		while (info->f_test > 0 && info->s_test > 0)
		{
			ft_rrr(a, b, 'y');
			info->f_test -= 1;
			info->s_test -= 1;
		}
	}
	while (info->f_test > 0)
	{
		if (choice == 0)
			ft_ra(a, 'y');
		else
			ft_rra(a, 'y');
		info->f_test -= 1;
	}
	while (info->s_test > 0)
	{
		ft_rrb(b, 'y');
		info->s_test -= 1;
	}
}

void	ft_choose_action3(t_pile *b, t_inf *info)
{
	if (info->s_test > 0)
	{
		while (info->s_test > 0)
		{
			ft_rb(b, 'y');
			info->s_test -= 1;
		}
	}
	else
	{
		info->s_test = -info->s_test;
		while (info->s_test > 0)
		{
			ft_rrb(b, 'y');
			info->s_test -= 1;
		}
	}
}

void	ft_choose_action2(t_pile *a, t_pile *b, t_inf *info)
{
	if (info->s_test > 0)
	{
		while (info->f_test > 0 && info->s_test > 0)
		{
			ft_rr(a, b, 'y');
			info->f_test -= 1;
			info->s_test -= 1;
		}
		while (info->f_test > 0)
		{
			ft_ra(a, 'y');
			info->f_test -= 1;
		}
		while (info->s_test > 0)
		{
			ft_rb(b, 'y');
			info->s_test -= 1;
		}
	}
	else
		ft_choose_action4(a, b, info, 0);
}

void	ft_choose_action1(t_pile *a, t_pile *b, t_inf *info)
{
	info->f_test = -info->f_test;
	if (info->s_test > 0)
	{
		while (info->s_test > 0)
		{
			ft_rb(b, 'y');
			info->s_test -= 1;
		}
		while (info->f_test > 0)
		{
			ft_rra(a, 'y');
			info->f_test -= 1;
		}
	}
	else
		ft_choose_action4(a, b, info, 1);
}

void	ft_choose_action(t_pile *a, t_pile *b, t_inf *info)
{
	while (ft_nlist_size(a->head) < info->size)
	{
		ft_test_actions(a, b, info, 0);
		if (info->f_test < 0)
			ft_choose_action1(a, b, info);
		else if (info->f_test > 0)
			ft_choose_action2(a, b, info);
		else
			ft_choose_action3(b, info);
		ft_pa(a, b, 'y');
	}
	last_sort(a, info, 0);
}
