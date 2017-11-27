/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:29:35 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:25:21 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_elem(t_arr **arr_a, long long int nb)
{
	if ((*arr_a) == NULL)
	{
		(*arr_a) = (t_arr *)malloc(sizeof(t_arr));
		(*arr_a)->nb = (long int)nb;
		(*arr_a)->next = NULL;
		(*arr_a)->prev = NULL;
		return ;
	}
	else
	{
		(*arr_a)->next = (t_arr *)malloc(sizeof(t_arr));
		(*arr_a)->next->nb = (long int)nb;
		(*arr_a)->next->next = NULL;
		(*arr_a)->next->prev = *arr_a;
		(*arr_a) = (*arr_a)->next;
	}
}

void	ft_get_data(t_arr **arr_a, char *str)
{
	if (ft_ifnumber(str) == 0)
		ft_error(2);
	ft_create_elem(arr_a, ft_atoi_ll(str));
}

void	ft_arrdel(t_arr **arr_a, t_arr **arr_b)
{
	if ((*arr_a) == NULL)
		return ;
	if ((*arr_a)->prev != NULL)
		while ((*arr_a)->prev != NULL)
			(*arr_a) = (*arr_a)->prev;
	while ((*arr_a)->next != NULL)
	{
		(*arr_a) = (*arr_a)->next;
		free((*arr_a)->prev);
	}
	if ((*arr_b) == NULL)
		return ;
	if ((*arr_b)->prev != NULL)
		while ((*arr_b)->prev != NULL)
			(*arr_b) = (*arr_b)->prev;
	while ((*arr_b)->next != NULL)
	{
		(*arr_b) = (*arr_b)->next;
		free((*arr_b)->prev);
	}
}

void	ft_get_from_file(char *file, t_arr **arr_a, int fd)
{
	char	*str;
	char	*buf;
	int		rd;

	str = (char *)malloc(sizeof(char));
	buf = (char *)malloc(sizeof(char));
	str[0] = '\0';
	while ((rd = (int)read(fd, buf, 1)) == 1 && buf[0] != ' ' && rd != 0)
		ft_strjoin_free(&str, buf);
	ft_get_data(arr_a, str);
	free(str);
	free(buf);
	if (rd != 0)
		ft_get_from_file(file, arr_a, fd);
}

void	ft_elemdel(t_arr **arr)
{
	if ((*arr)->prev != NULL)
	{
		(*arr) = (*arr)->prev;
		free((*arr)->next);
		(*arr)->next = NULL;
	}
	else
	{
		free((*arr));
		(*arr) = NULL;
	}
}
