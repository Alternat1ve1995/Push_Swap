/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:36:05 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:25:58 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_lstelem(t_elems **elems, int top, int bot)
{
	if ((*elems) == NULL)
	{
		(*elems) = (t_elems *)malloc(sizeof(t_elems));
		(*elems)->top = top;
		(*elems)->bot = bot;
		(*elems)->next = NULL;
		(*elems)->prev = NULL;
		return ;
	}
	else
	{
		(*elems)->next = (t_elems *)malloc(sizeof(t_elems));
		(*elems)->next->top = top;
		(*elems)->next->bot = bot;
		(*elems)->next->next = NULL;
		(*elems)->next->prev = *elems;
		(*elems) = (*elems)->next;
	}
}

void	ft_lstelemdel(t_elems **elems)
{
	if ((*elems)->prev != NULL)
	{
		(*elems) = (*elems)->prev;
		free((*elems)->next);
		(*elems)->next = NULL;
	}
	else
	{
		free((*elems));
		(*elems) = NULL;
	}
}

void	ft_move_parts(t_arr **parts, t_elems **elems)
{
	ft_goto_start(parts);
	while ((*parts)->next != NULL)
	{
		ft_create_lstelem(elems, (int)(*parts)->nb, 0);
		(*parts) = (*parts)->next;
	}
	ft_create_lstelem(elems, (int)(*parts)->nb, 0);
	ft_goto_start(parts);
	ft_lstgoto_end(elems);
}

int		ft_is_needed_to_rotate_b(t_arr **arr, int elems, int median)
{
	int		i;
	int		needed;

	i = 1;
	needed = 0;
	ft_goto_start(arr);
	while (i <= elems)
	{
		if ((*arr)->nb >= median)
			needed = i;
		if ((*arr)->next != NULL)
			(*arr) = (*arr)->next;
		else
			break ;
		i++;
	}
	ft_goto_start(arr);
	return (needed);
}

int		ft_is_needed_to_revrotate_b(t_arr **arr, int elems, int median)
{
	int		i;
	int		needed;

	i = 1;
	needed = 0;
	ft_goto_end(arr);
	while (i <= elems)
	{
		if ((*arr)->nb >= median)
			needed = i;
		if ((*arr)->prev != NULL)
			(*arr) = (*arr)->prev;
		else
			break ;
		i++;
	}
	ft_goto_start(arr);
	return (needed);
}
