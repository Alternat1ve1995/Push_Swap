/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:36:07 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:25:34 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_top_a(t_arr **a_a, t_arr **a_b, int **new_elems, int *p_e)
{
	ft_ecm("pb", &ft_pb, a_a, a_b);
	(*new_elems)[0]--;
	(*p_e)++;
}

static void	ft_skip_top_a(t_arr **a_a, t_arr **a_b, int **new_elems)
{
	ft_ecm("ra", &ft_ra, a_a, a_b);
	(*new_elems)[0]--;
	(*new_elems)[1]++;
}

static void	ft_push_bot_a(t_arr **a_a, t_arr **a_b, int **new_elems, int *p_e)
{
	ft_ecm("rra", &ft_rra, a_a, a_b);
	ft_ecm("pb", &ft_pb, a_a, a_b);
	(*p_e)++;
	(*new_elems)[1]--;
}

static void	ft_skip_bot_a(t_arr **a_a, t_arr **a_b, int **new_elems)
{
	ft_ecm("rra", &ft_rra, a_a, a_b);
	(*new_elems)[1]--;
	(*new_elems)[0]++;
}

void		ft_divide_a(t_arr **a_a, t_arr **a_b, t_elems **el, int new_elems[])
{
	int				median;
	int				pushed_elems;
	int				i;
	int				needed;

	if (new_elems[0] == 3 && new_elems[1] == 0 && ft_qsort_tree(a_a, a_b) != 0)
		return ;
	i = -1;
	pushed_elems = 0;
	median = ft_find_md_a(a_a, new_elems);
	needed = ft_is_needed_to_rotate_top_a(a_a, new_elems[0], median);
	while (++i < needed)
		if ((*a_a)->nb <= median)
			ft_push_top_a(a_a, a_b, &new_elems, &pushed_elems);
		else
			ft_skip_top_a(a_a, a_b, &new_elems);
	needed = ft_is_needed_to_rotate_bot_a(a_a, new_elems[1], median);
	i = -1;
	while (++i < needed && ft_i_love_norme(a_a))
		if ((*a_a)->nb <= median)
			ft_push_bot_a(a_a, a_b, &new_elems, &pushed_elems);
		else
			ft_skip_bot_a(a_a, a_b, &new_elems);
	ft_create_lstelem(el, pushed_elems, 0);
	ft_check_recursion(a_a, a_b, el, &new_elems);
}
