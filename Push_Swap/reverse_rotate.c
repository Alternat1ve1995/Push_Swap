/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:28:04 by vboiko            #+#    #+#             */
/*   Updated: 2017/04/12 18:40:56 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rra(t_arr **arr_a, t_arr **arr_b)
{
	t_arr	*tmp;

	*arr_b = *arr_b;
	if (*arr_a == NULL)
		return ;
	ft_goto_end(arr_a);
	if ((*arr_a) == NULL || (*arr_a)->prev == NULL)
		return ;
	tmp = (*arr_a);
	(*arr_a)->prev->next = NULL;
	ft_goto_start(arr_a);
	(*arr_a)->prev = tmp;
	(*arr_a)->prev->next = (*arr_a);
	(*arr_a)->prev->prev = NULL;
}

void	ft_rrb(t_arr **arr_a, t_arr **arr_b)
{
	t_arr	*tmp;

	*arr_a = *arr_a;
	if (*arr_b == NULL)
		return ;
	ft_goto_end(arr_b);
	if ((*arr_b) == NULL || (*arr_b)->prev == NULL)
		return ;
	tmp = (*arr_b);
	(*arr_b)->prev->next = NULL;
	ft_goto_start(arr_b);
	(*arr_b)->prev = tmp;
	(*arr_b)->prev->next = (*arr_b);
	(*arr_b)->prev->prev = NULL;
}

void	ft_rrr(t_arr **arr_a, t_arr **arr_b)
{
	ft_rra(arr_a, arr_b);
	ft_rrb(arr_a, arr_b);
}
