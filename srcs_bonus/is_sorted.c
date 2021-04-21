/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:29:04 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:24:21 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_is_sorted(t_nlist *nlist)
{
	if (nlist == NULL)
		return (0);
	else
	{
		while (nlist->next)
		{
			if (nlist->nbr > nlist->next->nbr)
				return (0);
			nlist = nlist->next;
		}
		return (1);
	}
}

int			ft_is_rsorted(t_nlist *nlist)
{
	if (nlist == NULL)
		return (0);
	else
	{
		while (nlist->next)
		{
			if (nlist->nbr < nlist->next->nbr)
				return (0);
			nlist = nlist->next;
		}
		return (1);
	}
}
