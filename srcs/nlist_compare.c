/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:45:10 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:26:17 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_get_median_index(t_pile *b, int i)
{
	if (i < ft_nlist_size(b->head) / 2)
		return (i);
	else
		return (-ft_nlist_size(b->head) + i);
}

void	*ft_rot_to_pb_next(t_pile *a, t_nlist *tmp, t_nlist *save, t_inf *info)
{
	if (tmp == a->tail && tmp->nbr > info->pb_rot[3]
		&& a->head->nbr < info->pb_rot[3])
		info->pb_rot[1] = info->pb_rot[4];
	if (tmp == a->head && tmp->nbr > info->pb_rot[3]
		&& save->nbr < info->pb_rot[3] && info->pb_rot[2] == 0)
	{
		info->pb_rot[0] = info->pb_rot[4];
		info->pb_rot[2] = 1;
	}
	info->pb_rot[4]++;
	if (tmp->nbr > info->pb_rot[3]
		&& save->nbr < info->pb_rot[3] && info->pb_rot[2] == 0)
	{
		info->pb_rot[0] = info->pb_rot[4];
		info->pb_rot[2] = 1;
	}
	if (tmp->nbr > info->pb_rot[3]
		&& save->nbr < info->pb_rot[3] && info->pb_rot[2] == 1)
		info->pb_rot[1] = info->pb_rot[4];
	return (tmp);
}

int		ft_nb_rot_to_pb(t_pile *a, t_inf *info, int val)
{
	t_nlist	*tmp;
	t_nlist	*save;

	info->pb_rot[0] = INT_MAX;
	info->pb_rot[1] = ft_nlist_size(a->head);
	info->pb_rot[2] = 0;
	info->pb_rot[3] = val;
	info->pb_rot[4] = 0;
	tmp = a->head->next;
	save = a->head;
	while (tmp)
	{
		ft_rot_to_pb_next(a, tmp, save, info);
		save = save->next;
		tmp = tmp->next;
	}
	if (info->pb_rot[0] < ft_nlist_size(a->head) - info->pb_rot[1])
		return (info->pb_rot[0]);
	else
		return (-(ft_nlist_size(a->head) - info->pb_rot[1]));
}

void	ft_test_actions(t_pile *a, t_pile *b, t_inf *info, int i)
{
	t_nlist	*tmp;
	int		val;

	tmp = b->head;
	info->f_test = INT_MAX;
	info->s_test = INT_MAX;
	while (tmp)
	{
		val = ft_nb_rot_to_pb(a, info, tmp->nbr);
		if (info->f_test == INT_MAX && info->s_test == INT_MAX)
		{
			info->f_test = val;
			info->s_test = ft_get_median_index(b, i);
		}
		if (ft_count_actions(val, ft_get_median_index(b, i))
		< ft_count_actions(info->f_test, info->s_test))
		{
			info->f_test = val;
			info->s_test = ft_get_median_index(b, i);
		}
		tmp = tmp->next;
		i++;
	}
}
