/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:52:02 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/20 16:57:29 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_counter(int val, int *count)
{
	while (val > 0)
	{
		*count += 1;
		val--;
	}
}

void		ft_count_actions3(int val2, int *count)
{
	if (val2 > 0)
		ft_counter(val2, count);
	else
	{
		val2 = -val2;
		ft_counter(val2, count);
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
		ft_counter(val1, count);
		ft_counter(val2, count);
	}
	else
	{
		val2 = -val2;
		ft_counter(val1, count);
		ft_counter(val2, count);
	}
}

void		ft_count_actions1(int val1, int val2, int *count)
{
	val1 = -val1;
	if (val2 > 0)
	{
		ft_counter(val2, count);
		ft_counter(val1, count);
	}
	else
	{
		val2 = -val2;
		while (val1 > 0 && val2 > 0)
		{
			*count += 1;
			val1--;
			val2--;
		}
		ft_counter(val1, count);
		ft_counter(val2, count);
	}
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
