/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_grading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:45:48 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:38:36 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_detect_point(t_type *type_list)
{
	int		point;
	double	num;

	point = 0;
	num = type_list->type_double;
	if (num > 9)
		while (num > 9)
		{
			num = num / 10;
			point++;
		}
	else if (num < 1)
		while (num < 1)
		{
			num = num * 10;
			point--;
		}
	return (point);
}

char		*ft_build_grading(t_lst *lst, t_value *vlst, t_type *type_list)
{
	int		point;
	char	*exp;
	int		i;

	i = 0;
	point = ft_detect_point(type_list);
	exp = ft_make_float(lst, type_list->type_double, vlst);
	if (vlst->accuracy_value != 0)
		vlst->accuracy_value = vlst->accuracy_value - 1;
	return (exp);
}

char		*ft_print_pointer(long long int nb, t_lst *lst, t_value *vlst)
{
	char	*point;
	int		len;
	char	*acc;

	acc = "0x";
	point = ft_make_hex(nb, lst);
	len = (int)ft_strlen(point);
	if (len < vlst->accuracy_value)
	{
		while (len < vlst->accuracy_value)
		{
			acc = ft_joinchar(acc, '0');
			len++;
		}
	}
	point = ft_strjoin(acc, point);
	return (point);
}
