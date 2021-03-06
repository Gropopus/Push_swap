/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:24:52 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/26 12:11:45 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** This function returns 1 if the nbr is located before,
** the median value and -1 if not.
*/

void	ft_init_tab(t_inf *info)
{
	info->med_rot[0] = 666666666;
	info->med_rot[1] = 666666666;
	info->med_rot[2] = 0;
	info->med_rot[3] = 0;
}

int		ft_is_rot_med(t_pile *a, t_inf *info)
{
	t_nlist	*tmp;
	int		size;

	ft_init_tab(info);
	tmp = a->head;
	size = ft_nlist_size(a->head);
	if (size <= 3)
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
	if (info->med_rot[0] <= size - info->med_rot[1])
		return (1);
	return (-1);
}
