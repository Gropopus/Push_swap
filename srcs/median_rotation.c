/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:24:52 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:36:21 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_tab(t_inf *info)
{
	info->med_rot[0] = INT_MAX;
	info->med_rot[1] = INT_MAX;
	info->med_rot[2] = 0;
	info->med_rot[3] = 0;
}

int		ft_is_rot_med(t_pile *a, t_inf *info)
{
	t_nlist	*tmp;

	ft_init_tab(info);
	tmp = a->head;
	if (ft_nlist_size(a->head) < 4)
		return (0);
	while (tmp)
	{
		if (tmp->nbr <= info->med && tmp->nbr != info->min
			&& info->med_rot[2] == 0)
		{
			info->med_rot[0] = info->med_rot[3];
			info->med_rot[2] = 1;
		}
		if (tmp->nbr <= info->med && tmp->nbr != info->min
			&& info->med_rot[2] == 1)
			info->med_rot[1] = info->med_rot[3];
		tmp = tmp->next;
		info->med_rot[3]++;
	}
	if (info->med_rot[0] <= ft_nlist_size(a->head) - info->med_rot[1])
		return (1);
	return (-1);
}
