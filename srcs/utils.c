/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:45:47 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:43:13 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_new_pile(void)
{
	t_pile	*new;

	if (!(new = malloc(sizeof(t_pile))))
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

int		ft_add_to_pile(t_pile *a, size_t nb)
{
	t_nlist	*new;

	if (!(new = malloc(sizeof(t_nlist))))
		return (0);
	new->nbr = nb;
	new->next = NULL;
	if (a->head == NULL)
	{
		a->head = new;
		a->tail = new;
	}
	else
	{
		a->tail->next = new;
		a->tail = new;
	}
	return (1);
}

int		ft_nlist_size(t_nlist *node)
{
	int	i;

	if (!node)
		return (0);
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	ft_free_pile(t_pile *pile)
{
	t_nlist *tmp;
	t_nlist *save;

	if (pile->head)
	{
		tmp = pile->head;
		save = pile->head->next;
		while (save)
		{
			free(tmp);
			tmp = save;
			save = save->next;
		}
		free(tmp);
	}
	free(pile);
}

t_pile	*ft_cpy_pile(t_pile *a)
{
	t_pile	*ret;
	t_nlist	*tmp;

	ret = ft_new_pile();
	tmp = a->head;
	while (tmp)
	{
		ft_add_to_pile(ret, tmp->nbr);
		tmp = tmp->next;
	}
	return (ret);
}
