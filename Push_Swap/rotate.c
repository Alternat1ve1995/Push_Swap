/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:28:41 by vboiko            #+#    #+#             */
/*   Updated: 2017/04/12 18:40:51 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_arr **arr_a, t_arr **arr_b)
{
	t_arr	*tmp;

	*arr_b = *arr_b;
	if (*arr_a == NULL)
		return ;
	ft_goto_start(arr_a);
	if ((*arr_a) == NULL || (*arr_a)->next == NULL)
		return ;
	tmp = (*arr_a);
	(*arr_a)->next->prev = NULL;
	ft_goto_end(arr_a);
	(*arr_a)->next = tmp;
	(*arr_a)->next->prev = (*arr_a);
	(*arr_a)->next->next = NULL;
}

void	ft_rb(t_arr **arr_a, t_arr **arr_b)
{
	t_arr	*tmp;

	*arr_a = *arr_a;
	if (*arr_b == NULL)
		return ;
	ft_goto_start(arr_b);
	if ((*arr_b) == NULL || (*arr_b)->next == NULL)
		return ;
	tmp = (*arr_b);
	(*arr_b)->next->prev = NULL;
	ft_goto_end(arr_b);
	(*arr_b)->next = tmp;
	(*arr_b)->next->prev = (*arr_b);
	(*arr_b)->next->next = NULL;
}

void	ft_rr(t_arr **arr_a, t_arr **arr_b)
{
	ft_ra(arr_a, arr_b);
	ft_rb(arr_a, arr_b);
}
