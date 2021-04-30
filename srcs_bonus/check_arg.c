/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:59:26 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/30 17:03:31 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long int	ft_atoi_limit(const char *str)
{
	long long int		nb;
	int					i;
	int					n;

	i = 0;
	nb = 0;
	n = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * n);
}

int				ft_check_double_nb(t_pile *a, char *av)
{
	long long int	nb;
	t_nlist			*tmp;

	nb = ft_atoi_limit(av);
	if (ft_strlen(av) > 11)
		return (-1);
	if (nb > 2147483647 || nb < -2147483648)
		return (-1);
	if (a)
	{
		tmp = a->head;
		while (tmp)
		{
			if (tmp->nbr == nb)
				return (-1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int				ft_check_arg_opt(t_pile *a, t_inf *info, char **av, int *nb_av)
{
	int				i;

	i = 1;
	if (*nb_av == 1 && av[*nb_av][0] == '-' && av[*nb_av][1] == 'v')
	{
		info->opt = 1;
		*nb_av += 1;
	}
	while (av[*nb_av][i])
	{
		if (ft_isdigit(av[*nb_av][i]) == 0 && av[*nb_av][i] != '-'
			&& av[*nb_av][i] != ' ')
			return (-1);
		i++;
	}
	if ((ft_check_double_nb(a, av[*nb_av])) < 0)
		return (-1);
	return (0);
}
