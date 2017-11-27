/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:37:26 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 19:06:53 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_if_sorted(t_arr **arr_a, t_arr **arr_b)
{
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	if ((*arr_a) != NULL && (*arr_b) == NULL)
	{
		while ((*arr_a)->next != NULL)
			if ((*arr_a)->next->nb > (*arr_a)->nb)
				(*arr_a) = (*arr_a)->next;
			else
				return (0);
	}
	else if ((*arr_b) != NULL)
		return (0);
	else if ((*arr_a) == NULL)
		return (0);
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	return (1);
}

static void	ft_check_duplicates(long int *numbers, int len)
{
	int		duplicates;
	int		k;
	int		i;

	duplicates = 0;
	k = 0;
	i = 0;
	while (k < len)
	{
		i = 0;
		while (i < len)
		{
			if (numbers[i] == numbers[k])
				duplicates++;
			i++;
		}
		if (duplicates != 1)
			ft_error(1);
		duplicates = 0;
		k++;
	}
}

void		ft_input_validation(t_arr **arr)
{
	long int	*numbers;
	int			len;
	int			i;

	i = 0;
	len = ft_lstlen(arr);
	if (len != 0)
	{
		numbers = (long int *)malloc(sizeof(long int) * len);
		while ((*arr)->next != NULL)
		{
			if ((*arr)->nb > INT32_MAX || (*arr)->nb < INT32_MIN)
				ft_error(3);
			numbers[i] = (*arr)->nb;
			i++;
			(*arr) = (*arr)->next;
		}
		if ((*arr)->nb > INT32_MAX || (*arr)->nb < INT32_MIN)
			ft_error(3);
		numbers[i] = (*arr)->nb;
		ft_check_duplicates(numbers, len);
		free(numbers);
		numbers = NULL;
	}
}
