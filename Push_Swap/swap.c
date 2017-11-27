/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:29:50 by vboiko            #+#    #+#             */
/*   Updated: 2017/04/12 18:40:47 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_arr **arr_a, t_arr **arr_b)
{
	long int	n;

	n = 0;
	*arr_b = *arr_b;
	if ((*arr_a) != NULL)
	{
		if ((*arr_a)->next != NULL)
		{
			n = (*arr_a)->nb;
			(*arr_a)->nb = (*arr_a)->next->nb;
			(*arr_a)->next->nb = n;
		}
	}
	return ;
}

void	ft_sb(t_arr **arr_a, t_arr **arr_b)
{
	long int	n;

	n = 0;
	*arr_a = *arr_a;
	if ((*arr_b) != NULL)
	{
		if ((*arr_b)->next != NULL)
		{
			n = (*arr_b)->nb;
			(*arr_b)->nb = (*arr_b)->next->nb;
			(*arr_b)->next->nb = n;
		}
	}
	return ;
}

void	ft_ss(t_arr **arr_a, t_arr **arr_b)
{
	long int	n;

	n = 0;
	if ((*arr_a) != NULL)
	{
		if ((*arr_a)->next != NULL)
		{
			n = (*arr_a)->nb;
			(*arr_a)->nb = (*arr_a)->next->nb;
			(*arr_a)->next->nb = n;
		}
	}
	if ((*arr_b) != NULL)
	{
		if ((*arr_b)->next != NULL)
		{
			n = (*arr_b)->nb;
			(*arr_b)->nb = (*arr_b)->next->nb;
			(*arr_b)->next->nb = n;
		}
	}
	return ;
}
