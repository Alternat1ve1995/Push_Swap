/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elems_cases.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:40:44 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:27:11 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_gc(t_arr **a, t_arr **b, int i)
{
	if (i == 1)
	{
		ft_rra(a, b);
		ft_goto_start(a);
		ft_sa(a, b);
		ft_printf("rra\nsa\n");
	}
	else if (i == 2)
	{
		ft_ra(a, b);
		ft_goto_start(a);
		ft_sa(a, b);
		ft_printf("ra\nsa\n");
	}
	else if (i == 3)
	{
		ft_ra(a, b);
		ft_printf("ra\n");
	}
}

void	ft_fdiv(t_arr **arr_a, t_arr **arr_b, t_arr **parts, int *elems)
{
	ft_pb(arr_a, arr_b);
	(*parts)->nb++;
	ft_printf("pb\n");
	(*elems)++;
}

int		ft_precheck(t_arr **a_a, t_arr **a_b, t_elems **elems, int *new_elems)
{
	if ((*elems)->top + (*elems)->bot == 0)
		ft_lstelemdel(elems);
	if ((*elems)->top == 0 && (*elems)->bot == ft_lstlen(a_b))
	{
		(*elems)->top = (*elems)->bot;
		(*elems)->bot = 0;
	}
	if ((*elems)->top < 3 && (*elems)->bot == 0)
	{
		*new_elems = (*elems)->top;
		while ((*elems)->top > 0)
		{
			ft_ecm("pa", &ft_pa, a_a, a_b);
			(*elems)->top--;
		}
		return (1);
	}
	return (-1);
}
