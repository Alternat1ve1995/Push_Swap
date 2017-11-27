/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:28:58 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:26:09 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_goto_start(t_arr **arr)
{
	if ((*arr) != NULL)
		if ((*arr)->prev != NULL)
			while ((*arr)->prev != NULL)
				(*arr) = (*arr)->prev;
}

void	ft_goto_end(t_arr **arr)
{
	if ((*arr) != NULL)
		if ((*arr)->next != NULL)
			while ((*arr)->next != NULL)
				(*arr) = (*arr)->next;
}

void	ft_lstgoto_start(t_elems **arr)
{
	if ((*arr) != NULL)
		if ((*arr)->prev != NULL)
			while ((*arr)->prev != NULL)
				(*arr) = (*arr)->prev;
}

void	ft_lstgoto_end(t_elems **arr)
{
	if ((*arr) != NULL)
		if ((*arr)->next != NULL)
			while ((*arr)->next != NULL)
				(*arr) = (*arr)->next;
}

int		ft_i_love_norme(t_arr **arr)
{
	if ((*arr) != NULL)
		if ((*arr)->next != NULL)
			while ((*arr)->next != NULL)
				(*arr) = (*arr)->next;
	return (1);
}
