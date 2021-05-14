/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:45:10 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/12 11:55:10 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** function to find the location of the median index
*/

int		ft_get_median_index(t_pile *b, int i)
{
	int size_b;

	size_b = ft_nlist_size(b->head);
	if (i < (size_b / 2))
		return (i);
	return (-size_b + i);
}

void	ft_reset_tab(t_pile *a, t_inf *info, int nb)
{
	info->a = 666666666;
	info->b = ft_nlist_size(a->head);
	info->c = 0;
	info->d = nb;
	info->e = 0;
}

void	*ft_rot_to_pb_next(t_pile *a, t_nlist *tmp, t_nlist *prev, t_inf *info)
{
	while (tmp)
	{
		if (tmp == a->tail && tmp->nbr > info->d && a->head->nbr < info->d)
			info->b = info->e;
		if (tmp == a->head && tmp->nbr > info->d
			&& prev->nbr < info->d && info->c == 0)
		{
			info->a = info->e;
			info->c = 1;
		}
		info->e++;
		if (tmp->nbr > info->d && prev->nbr < info->d && info->c == 0)
		{
			info->a = info->e;
			info->c = 1;
		}
		if (tmp->nbr > info->d && prev->nbr < info->d && info->c == 1)
			info->b = info->e;
		prev = prev->next;
		tmp = tmp->next;
	}
	return (tmp);
}

/*
** calculate the number of rotations to do before stack a is ready for b->nbr
** to be pushed back and returns this number.
*/

int		ft_nb_rot_to_pb(t_pile *a, t_inf *info)
{
	t_nlist	*tmp;
	t_nlist	*previous;

	tmp = a->head->next;
	previous = a->head;
	ft_rot_to_pb_next(a, tmp, previous, info);
	if (info->a < ft_nlist_size(a->head) - info->b)
		return (info->a);
	return (-(ft_nlist_size(a->head) - info->b));
}

/*
** this function set the 2 tests variables:
** -> one with the number of rotations to do before b->nbr
** is well placed (f_test = val)
** ->the distance that separates the number from the median index
** (s_test = ft_get_median_index)
*/

int		ft_test_actions(t_pile *a, t_pile *b, t_inf *info, int i)
{
	t_nlist	*tmp;
	int		nb_rot;

	tmp = b->head;
	info->f_test = -666666666;
	info->s_test = -666666666;
	while (tmp)
	{
		ft_reset_tab(a, info, tmp->nbr);
		nb_rot = ft_nb_rot_to_pb(a, info);
		if (i == 0)
		{
			info->f_test = nb_rot;
			info->s_test = ft_get_median_index(b, i);
		}
		if (ft_count_actions(nb_rot, ft_get_median_index(b, i))
			< ft_count_actions(info->f_test, info->s_test))
		{
			info->f_test = nb_rot;
			info->s_test = ft_get_median_index(b, i);
		}
		tmp = tmp->next;
		i++;
	}
	return (info->f_test);
}
