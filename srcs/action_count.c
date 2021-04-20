/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:52:02 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/20 15:23:03 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_count_actions_last(int val1, int val2, int *count, int choice)
{
	val2 = -val2;
	if (choice == 1)
	{
		while (val1 > 0 && val2 > 0)
		{
			*count += 1;
			val1--;
			val2--;
		}
	}
	while (val1 > 0)
	{
		*count += 1;
		val1--;
	}
	while (val2 > 0)
	{
		*count += 1;
		val2--;
	}
}

void		ft_count_actions3(int val2, int *count)
{
	if (val2 > 0)
	{
		while (val2 > 0)
		{
			*count += 1;
			val2--;
		}
	}
	else
	{
		val2 = -val2;
		while (val2 > 0)
		{
			*count += 1;
			val2--;
		}
	}
}

void		ft_count_actions2(int val1, int val2, int *count)
{
	if (val2 > 0)
	{
		while (val1 > 0 && val2 > 0)
		{
			*count += 1;
			val1--;
			val2--;
		}
		while (val1 > 0)
		{
			*count += 1;
			val1--;
		}
		while (val2 > 0)
		{
			*count += 1;
			val2--;
		}
	}
	else
		ft_count_actions_last(val1, val2, count, 0);
}

void		ft_count_actions1(int val1, int val2, int *count)
{
	val1 = -val1;
	if (val2 > 0)
	{
		while (val2 > 0)
		{
			*count += 1;
			val2--;
		}
		while (val1 > 0)
		{
			*count += 1;
			val1--;
		}
	}
	else
		ft_count_actions_last(val1, val2, count, 1);
}

/*
** count the number of actions and returns it.
** val1 is the nb of rotations to do
** val2 is the number's distance from the median index
*/

int			ft_count_actions(int val1, int val2)
{
	int count;

	count = 0;
	if (val1 < 0)
		ft_count_actions1(val1, val2, &count);
	else if (val1 > 0)
		ft_count_actions2(val1, val2, &count);
	else
		ft_count_actions3(val2, &count);
	return (count);
}
