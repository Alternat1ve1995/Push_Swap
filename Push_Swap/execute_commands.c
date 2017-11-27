/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:21:02 by vboiko            #+#    #+#             */
/*   Updated: 2017/04/12 18:41:20 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		ft_print_output(t_arr **arr_a, t_arr **arr_b)
{
	if (*arr_a != NULL && *arr_b != NULL)
		printf("a: [%5ld] | [%-5ld] :b\n", (*arr_a)->nb, (*arr_b)->nb);
	else if (*arr_a != NULL && *arr_b == NULL)
		printf("a: [%5ld] | [%-5s] :b\n", (*arr_a)->nb, "NULL");
	else if (*arr_a == NULL && *arr_b != NULL)
		printf("a: [%5s] | [%-5ld] :b\n", "NULL", (*arr_b)->nb);
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
	{
		while ((*arr_a) != NULL || (*arr_b) != NULL)
		{
			ft_print_output(arr_a, arr_b);
			if (*arr_a != NULL)
				(*arr_a) = (*arr_a)->next;
			if (*arr_b != NULL)
				(*arr_b) = (*arr_b)->next;
		}
	}
	ft_print_output(arr_a, arr_b);
	(*arr_b) = temp_b;
	(*arr_a) = temp_a;
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
}

static int		ft_try_exexute_cm(char **str, t_arr **arr_a, t_arr **arr_b)
{
	if (ft_strcmp(*str, "sa\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_sa));
	else if (ft_strcmp(*str, "sb\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_sb));
	else if (ft_strcmp(*str, "ss\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_ss));
	else if (ft_strcmp(*str, "pb\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_pb));
	else if (ft_strcmp(*str, "pa\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_pa));
	else if (ft_strcmp(*str, "ra\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_ra));
	else if (ft_strcmp(*str, "rb\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rb));
	else if (ft_strcmp(*str, "rr\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rr));
	else if (ft_strcmp(*str, "rra\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rra));
	else if (ft_strcmp(*str, "rrb\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rrb));
	else if (ft_strcmp(*str, "rrr\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_rrr));
	else if (ft_strcmp(*str, "dbg\n") == 0)
		return (ft_do_cm(str, arr_a, arr_b, &ft_print_arr));
	return (0);
}

int				ft_get_command(char **str, t_arr **arr_a, t_arr **arr_b)
{
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	return (ft_try_exexute_cm(str, arr_a, arr_b));
}
