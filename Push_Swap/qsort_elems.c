/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:17:46 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:26:39 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_cm(t_arr **arr_a, t_arr **arr_b, int i)
{
	if (i == 1)
	{
		ft_ecm("sa", &ft_sa, arr_a, arr_b);
		ft_ecm("ra", &ft_ra, arr_a, arr_b);
		ft_goto_start(arr_a);
		ft_ecm("sa", &ft_sa, arr_a, arr_b);
		ft_ecm("rra", &ft_rra, arr_a, arr_b);
	}
	else if (i == 2)
	{
		ft_ecm("pb", &ft_pb, arr_a, arr_b);
		ft_ecm("sa", &ft_sa, arr_a, arr_b);
		ft_ecm("pa", &ft_pa, arr_a, arr_b);
	}
	else if (i == 3)
	{
		ft_ecm("sa", &ft_sa, arr_a, arr_b);
		ft_ecm("ra", &ft_ra, arr_a, arr_b);
		ft_goto_start(arr_a);
		ft_ecm("sa", &ft_sa, arr_a, arr_b);
		ft_ecm("rra", &ft_rra, arr_a, arr_b);
		ft_goto_start(arr_a);
		ft_ecm("sa", &ft_sa, arr_a, arr_b);
	}
	return (1);
}

int			ft_qsort_tree(t_arr **arr_a, t_arr **arr_b)
{
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	if ((*arr_a)->N->nb > (*arr_a)->nb && (*arr_a)->NN->nb > (*arr_a)->N->nb)
		return (1);
	else if (((*arr_a)->N->nb < (*arr_a)->nb) && ((ARA)->NN->nb > (*arr_a)->nb))
	{
		ft_ecm("sa", &ft_sa, arr_a, arr_b);
		return (1);
	}
	else if (((ARA)->N->nb < R) && (M > (ARA)->N->nb) && (M < R))
		return (ft_get_cm(arr_a, arr_b, 1));
	else if (((ARA)->NN->nb < (ARA)->N->nb) && ((ARA)->nb < (ARA)->NN->nb))
		return (ft_get_cm(arr_a, arr_b, 2));
	else if (((ARA)->nb > (ARA)->N->nb) && ((ARA)->N->nb > (ARA)->NN->nb))
		return (ft_get_cm(arr_a, arr_b, 3));
	ft_goto_start(arr_a);
	return (0);
}
