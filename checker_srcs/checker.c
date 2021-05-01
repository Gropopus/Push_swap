/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:09:58 by thsembel          #+#    #+#             */
/*   Updated: 2021/05/01 13:17:08 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_is_ok(t_pile *a, t_pile *b)
{
	t_nlist *tmp;

	if (!a->head || b->head != NULL)
		return (-1);
	tmp = a->head;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int		action_manager(t_pile *a, t_pile *b, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		ft_pa(a, b, 'n');
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(a, b, 'n');
	else if (ft_strcmp(line, "sa") == 0)
		ft_sa(a, 'n');
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(b, 'n');
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(a, b, 'n');
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(a, 'n');
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(b, 'n');
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(a, b, 'n');
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(a, 'n');
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(b, 'n');
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(a, b, 'n');
	else
		return (-1);
	return (0);
}

int		ft_handle_input(t_pile *a, t_pile *b)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if ((action_manager(a, b, line)) < 0)
		{
			if ((ft_strcmp(line, "finish")) == 0)
			{
				free(line);
				return (0);
			}
			free(line);
			line = NULL;
			return (-1);
		}
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	return (0);
}

int		ft_add_and_check(t_pile *a, int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		return (-1);
	while (i < ac)
	{
		if ((ft_check_arg(a, av[i])) < 0)
			return (-1);
		ft_add_to_pile(a, ft_atoi(av[i]));
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_pile *a;
	t_pile *b;

	if ((a = ft_new_pile()) == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if ((b = ft_new_pile()) == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if ((ft_add_and_check(a, ac, av)) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if ((ft_handle_input(a, b)) < 0)
		ft_error(a, b, NULL);
	else
		display_result(a, b);
	return (0);
}
