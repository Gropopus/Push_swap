/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:52:11 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/30 17:04:36 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int		ascending_sort(t_pile *a, int swap, int nb)
{
	t_nlist	*tmp;
	t_nlist	*list;

	list = NULL;
	if (a->head == NULL)
		return (-1);
	while (swap)
	{
		swap = 0;
		tmp = a->head;
		while (tmp->next != list)
		{
			if (tmp->nbr > tmp->next->nbr)
			{
				nb = tmp->nbr;
				tmp->nbr = tmp->next->nbr;
				tmp->next->nbr = nb;
				swap = 1;
			}
			tmp = tmp->next;
		}
		list = tmp;
	}
	return (1);
}

int		ft_get_info(t_inf *info, t_pile *a, int i, int mid_index)
{
	t_pile	*tmp;
	t_nlist	*sorted;

	if ((ft_is_sorted(a->head) == 1))
	{
		ft_free_pile(a);
		return (2);
	}
	tmp = ft_cpy_pile(a);
	if ((ascending_sort(tmp, 1, 0)) < 0)
		return (-1);
	mid_index = info->size / 2;
	info->min = tmp->head->nbr;
	info->max = tmp->tail->nbr;
	sorted = tmp->head;
	while (sorted)
	{
		if (i == mid_index)
			info->med = sorted->nbr;
		sorted = sorted->next;
		i++;
	}
	ft_free_pile(tmp);
	return (0);
}

int		set_pile(t_pile *a, t_inf *info, int ac, char **av)
{
	int		i;
	size_t	nb;

	i = 1;
	while (i < ac)
	{
		if (ft_check_arg_opt(a, info, av, &i) < 0)
		{
			ft_error(a, NULL, info);
			return (-1);
		}
		nb = ft_atoi(av[i]);
		if ((ft_add_to_pile(a, nb)) == 0)
			return (-1);
		i++;
	}
	info->size = ft_nlist_size(a->head);
	if ((nb = ft_get_info(info, a, 0, 0)) < 0)
	{
		ft_error(a, NULL, info);
		return (-1);
	}
	else if (nb == 2)
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	t_inf	*info;

	if (ac == 1)
		return (0);
	if ((a = ft_new_pile()) == NULL)
		return (-1);
	if ((info = malloc(sizeof(t_inf))) == NULL)
		return (-1);
	info->opt = 0;
	if (((set_pile(a, info, ac, av)) < 0) || ((b = ft_new_pile()) == NULL))
	{
		free(info);
		return (-1);
	}
	algo_manager(a, b, info);
	ft_free_pile(a);
	ft_free_pile(b);
	free(info);
	return (0);
}
