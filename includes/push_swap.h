/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:41:31 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/21 17:51:47 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# define INT_MAX 2147483647
# define RED             "\033[0;31m"
# define GREEN           "\033[0;32m"
# define NC              "\033[0m"

typedef struct			s_nlist
{
	int					nbr;
	struct s_nlist		*next;
}						t_nlist;

typedef struct			s_pile
{
	t_nlist				*head;
	t_nlist				*tail;
}						t_pile;

typedef struct			s_inf
{

	int					min;
	int					max;
	int					med;
	int					size;
	int					opt;
	int					med_rot[4];
	int					pb_rot[5];
	int					f_test;
	int					s_test;
}						t_inf;
/*
**		error.c
*/
void					ft_error(t_pile *a, t_pile *b, t_inf *info);
/*
**		utils.c
*/
void					ft_free_pile(t_pile *pile);
t_pile					*ft_new_pile(void);
t_pile					*ft_cpy_pile(t_pile *a);
int						ft_add_to_pile(t_pile *a, size_t nb);
int						ft_nlist_size(t_nlist *nlist);
/*
**		check_arg.c
*/
int						ft_check_arg(t_pile *a, char *av);
/*
**		algo.c
*/
void					algo_manager(t_pile *a, t_pile *b, t_inf *info);
/*
**		is_sorted.c
*/
int						ft_is_sorted(t_nlist *nlist);
int						ft_is_rsorted(t_nlist *nlist);
/*
**		push_a_b.c
*/
void					ft_pa(t_pile *a, t_pile *b, char perm);
void					ft_pb(t_pile *a, t_pile *b, char perm);
/*
**		swap_a_b.c
*/
void					ft_sa(t_pile *a, char perm);
void					ft_sb(t_pile *a, char perm);
void					ft_ss(t_pile *a, t_pile *b, char perm);
/*
**		rotate_a_b.c
*/
void					ft_ra(t_pile *a, char perm);
void					ft_rb(t_pile *a, char perm);
void					ft_rr(t_pile *a, t_pile *b, char perm);
/*
**		reverse_rot_a_b.c
*/
void					ft_rra(t_pile *a, char perm);
void					ft_rrb(t_pile *a, char perm);
void					ft_rrr(t_pile *a, t_pile *b, char perm);
/*
**		choose_action.c
*/
void					ft_choose_action(t_pile *a, t_pile *b, t_inf *info);
/*
**		big_pile_algo.c
*/
void					big_pile_algo(t_pile *a, t_pile *b,
	t_inf *data, int val);
void					last_sort(t_pile *a, t_inf *info, int i);
/*
**		median_rotation.c
*/
int						ft_is_rot_med(t_pile *a, t_inf *info);
/*
**		nlist_compare.c
*/
void					ft_test_actions(t_pile *a, t_pile *b,
	t_inf *info, int i);
/*
**		action_count.c
*/
int						ft_count_actions(int val1, int val2);
/*
**		checker.c
*/
int						ft_is_ok(t_pile *a, t_pile *b);
/*
**		checker2.c
*/
void					display_result(t_pile *a, t_pile *b);
/*
**		display_bonus.c
*/
void					ft_print_piles(t_pile *a, t_pile *b, int perm);
void					ft_last_sort_bonus(t_pile *a, t_inf *info,
		int i, int min_index);
int						ft_check_arg_opt(t_pile *a, t_inf *info, char **av,
		int *nb_av);
#endif
