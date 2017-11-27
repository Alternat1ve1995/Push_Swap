/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:37:26 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 16:32:20 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_check_sorted(t_arr **arr_a, t_arr **arr_b, int op, int o)
{
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	if ((*arr_a) != NULL && (*arr_b) == NULL)
	{
		while ((*arr_a)->next != NULL)
			if ((*arr_a)->next->nb > (*arr_a)->nb)
				(*arr_a) = (*arr_a)->next;
			else
				ft_error(4);
	}
	else if ((*arr_b) != NULL)
		ft_error(5);
	else if ((*arr_a) == NULL)
		ft_error(6);
	ft_printf("OK\n");
	if (o == 1)
		printf("operations : %d\n", op);
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
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
