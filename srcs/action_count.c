/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:52:02 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/30 12:28:07 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_counter(int nb_action, int *count)
{
	while (nb_action > 0)
	{
		*count += 1;
		nb_action--;
	}
}

void		ft_count_actions_two(int nb_rot, int med_i, int *count)
{
	if (med_i > 0)
	{
		while (nb_rot > 0 && med_i > 0)
		{
			*count += 1;
			nb_rot--;
			med_i--;
		}
		ft_counter(nb_rot, count);
		ft_counter(med_i, count);
	}
	else
	{
		med_i = -med_i;
		ft_counter(nb_rot, count);
		ft_counter(med_i, count);
	}
}

void		ft_count_actions_first(int nb_rot, int med_i, int *count)
{
	nb_rot = -nb_rot;
	if (med_i > 0)
	{
		ft_counter(med_i, count);
		ft_counter(nb_rot, count);
	}
	else
	{
		med_i = -med_i;
		while (nb_rot > 0 && med_i > 0)
		{
			*count += 1;
			nb_rot--;
			med_i--;
		}
		ft_counter(nb_rot, count);
		ft_counter(med_i, count);
	}
}

int			ft_count_actions(int nb_rot, int med_i)
{
	int count;

	count = 0;
	if (nb_rot < 0)
		ft_count_actions_first(nb_rot, med_i, &count);
	else if (nb_rot > 0)
		ft_count_actions_two(nb_rot, med_i, &count);
	else
	{
		if (med_i > 0)
			ft_counter(med_i, &count);
		else
		{
			med_i = -med_i;
			ft_counter(med_i, &count);
		}
	}
	return (count);
}
