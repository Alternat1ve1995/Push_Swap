/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:21:02 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/17 14:46:57 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		ft_print_output(t_arr **a, t_arr **b)
{
	if (*a != NULL && *b != NULL)
		printf("\e[32ma:\e[33m[%5ld]\e[94m|\e[33m[%-5ld]\e[91m:b\n",
		(*a)->nb, (*b)->nb);
	else if (*a != NULL && *b == NULL)
		printf("\e[32ma:\e[33m[%5ld]\e[94m|\e[33m[%-5s]\e[91m:b\n",
		(*a)->nb, "NULL");
	else if (*a == NULL && *b != NULL)
		printf("\e[32ma:\e[33m[%5s]\e[94m|\e[33m[%-5ld]\e[91m:b\n",
		"NULL", (*b)->nb);
}

static int		ft_do_cm(char **str, ARR, void (*f)(t_arr**, t_arr**))
{
	int		i;

	i = 0;
	f(arr_a, arr_b);
	ft_strsub_free(str, 0, 0);
	return (1);
}

void			ft_print_arr(t_arr **arr_a, t_arr **arr_b)
{
	t_arr	*temp_a;
	t_arr	*temp_b;

	temp_a = NULL;
	temp_b = NULL;
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	temp_a = (*arr_a);
	temp_b = (*arr_b);
	if ((*arr_a) != NULL || (*arr_b) != NULL)
		while ((*arr_a) != NULL || (*arr_b) != NULL)
		{
			ft_print_output(arr_a, arr_b);
			if (*arr_a != NULL)
				(*arr_a) = (*arr_a)->next;
			if (*arr_b != NULL)
				(*arr_b) = (*arr_b)->next;
		}
	ft_print_output(arr_a, arr_b);
	(*arr_b) = temp_b;
	(*arr_a) = temp_a;
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	ft_printf("\n\n");
}

static int		ft_try_exexute_cm(char **str, t_arr **arr_a, t_arr **arr_b)
{
	if (ft_strcmp(*str, "sa") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_sa));
	else if (ft_strcmp(*str, "sb") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_sb));
	else if (ft_strcmp(*str, "ss") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_ss));
	else if (ft_strcmp(*str, "pb") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_pb));
	else if (ft_strcmp(*str, "pa") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_pa));
	else if (ft_strcmp(*str, "ra") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_ra));
	else if (ft_strcmp(*str, "rb") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rb));
	else if (ft_strcmp(*str, "rr") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rr));
	else if (ft_strcmp(*str, "rra") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rra));
	else if (ft_strcmp(*str, "rrb") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rrb));
	else if (ft_strcmp(*str, "rrr") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rrr));
	else if (ft_strcmp(*str, "dbg") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_print_arr));
	return (0);
}

int				ft_get_command(char **str, t_arr **arr_a, t_arr **arr_b)
{
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	return (ft_try_exexute_cm(str, arr_a, arr_b));
}
