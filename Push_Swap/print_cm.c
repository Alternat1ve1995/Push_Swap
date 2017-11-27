/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:44:43 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:26:14 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ecm(char *str, void (*f)(t_arr**, t_arr**), t_arr **a_a, t_arr **a_b)
{
	f(a_a, a_b);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	ft_goto_start(a_a);
	ft_goto_start(a_b);
}

void	ft_push_sort(t_arr **arr_a, t_arr **arr_b, t_arr **elems)
{
	while ((*elems)->nb > 0)
	{
		ft_ecm("pa", &ft_pa, arr_a, arr_b);
		(*elems)->nb--;
	}
	ft_sort_two_elems(arr_a, arr_b);
	ft_elemdel(elems);
}

void	ft_revpush_sort(t_arr **arr_a, t_arr **arr_b, t_arr **elems)
{
	while ((*elems)->nb < 0)
	{
		ft_ecm("rrb", &ft_rrb, arr_a, arr_b);
		ft_ecm("pa", &ft_pa, arr_a, arr_b);
		(*elems)->nb++;
	}
	ft_sort_two_elems(arr_a, arr_b);
	ft_elemdel(elems);
	ft_goto_start(arr_b);
}
