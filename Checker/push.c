/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:23:21 by vboiko            #+#    #+#             */
/*   Updated: 2017/04/12 18:41:05 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		ft_push_new_b(t_arr **arr_a, t_arr **arr_b)
{
	ft_goto_start(arr_b);
	(*arr_b)->prev = (t_arr *)malloc(sizeof(t_arr));
	(*arr_b)->prev->prev = NULL;
	(*arr_b)->prev->next = (*arr_b);
	(*arr_b)->prev->nb = (*arr_a)->nb;
	if ((*arr_a)->next == NULL)
		ft_memdel((void **)(arr_a));
	else
	{
		(*arr_a) = (*arr_a)->next;
		if (*arr_a != NULL)
		{
			free((*arr_a)->prev);
			(*arr_a)->prev = NULL;
		}
	}
	ft_goto_start(arr_b);
}

static void		ft_push_new_a(t_arr **arr_a, t_arr **arr_b)
{
	ft_goto_start(arr_a);
	(*arr_a)->prev = (t_arr *)malloc(sizeof(t_arr));
	(*arr_a)->prev->prev = NULL;
	(*arr_a)->prev->next = (*arr_a);
	(*arr_a)->prev->nb = (*arr_b)->nb;
	if ((*arr_b)->next == NULL)
		ft_memdel((void **)arr_b);
	else
	{
		(*arr_b) = (*arr_b)->next;
		if (*arr_b != NULL)
		{
			free((*arr_b)->prev);
			(*arr_b)->prev = NULL;
		}
	}
	ft_goto_start(arr_a);
}

void			ft_pb(t_arr **arr_a, t_arr **arr_b)
{
	if ((*arr_a) == NULL)
		return ;
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	if (*arr_b == NULL)
	{
		(*arr_b) = (t_arr *)malloc(sizeof(t_arr));
		(*arr_b)->next = NULL;
		(*arr_b)->prev = NULL;
		(*arr_b)->nb = (*arr_a)->nb;
		(*arr_a) = (*arr_a)->next;
		free((*arr_a)->prev);
		(*arr_a)->prev = NULL;
	}
	else
		ft_push_new_b(arr_a, arr_b);
}

void			ft_pa(t_arr **arr_a, t_arr **arr_b)
{
	if ((*arr_b) == NULL)
		return ;
	ft_goto_start(arr_b);
	ft_goto_start(arr_a);
	if (*arr_a == NULL)
	{
		(*arr_a) = (t_arr *)malloc(sizeof(t_arr));
		(*arr_a)->next = NULL;
		(*arr_a)->prev = NULL;
		(*arr_a)->nb = (*arr_b)->nb;
		(*arr_b) = (*arr_b)->next;
		free((*arr_b)->prev);
		(*arr_b)->prev = NULL;
	}
	else
		ft_push_new_a(arr_a, arr_b);
}
