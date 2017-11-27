/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_expon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:26:07 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:38:24 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_make_expon(t_type *type_list, t_lst *lst, t_value *vlst)
{
	char	*exp;
	int		point;

	point = 0;
	exp = "\0";
	if (type_list->type_double < 0)
		type_list->type_double = -type_list->type_double;
	if (type_list->type_double < 0)
		exp = ft_joinchar(exp, '-');
	if (type_list->type_double > 9)
		while (type_list->type_double > 9)
		{
			type_list->type_double = type_list->type_double / 10;
			point++;
		}
	else if (type_list->type_double < 1)
		while (type_list->type_double < 1)
		{
			type_list->type_double = type_list->type_double * 10;
			point--;
		}
	exp = point < 0 ? ft_joinchar(A) : ft_joinchar(B);
	if ((point < 10 && point >= 0) || (point <= 0 && point > -10))
		exp = ft_joinchar(exp, '0');
	return (ft_strjoin(exp, ft_itoa(ABS(point))));
}
