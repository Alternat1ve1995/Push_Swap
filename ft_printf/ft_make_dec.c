/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:01:40 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:38:55 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_modhh(t_lst *lst, t_type *type_list)
{
	if (lst->type != 'D')
		lst->str = ft_itoa((char)type_list->type_int);
	else
		lst->str = ft_itoa_ll(type_list->type_int);
	return (lst->str);
}

static char	*ft_modh(t_lst *lst, t_type *type_list)
{
	if (lst->type != 'D')
		lst->str = ft_itoa((short int)type_list->type_int);
	else
		lst->str = ft_itoa_ll(type_list->type_int);
	return (lst->str);
}

static void	ft_checkacc(int *a, int *b)
{
	(*a)++;
	(*b) = 1;
}

char		*ft_make_accdec(t_lst *lst, t_value *vlst, t_type *type_list)
{
	int		flag;

	flag = 0;
	if (type_list->type_int == 0 && (ZEROACC) && ISP && vlst->width_value != 0)
		return ("\0");
	if (vlst->accuracy_value == -1)
		ft_checkacc(&vlst->accuracy_value, &flag);
	if (lst->modificator == NULL && lst->type != 'D')
		lst->str = ft_itoa((int)type_list->type_int);
	else if (lst->modificator == NULL && lst->type == 'D')
		lst->str = ft_itoa_ll(type_list->type_int);
	else if (ft_strcmp(lst->modificator, "h") == 0)
		lst->str = ft_modh(lst, type_list);
	else if (ft_strcmp(lst->modificator, "hh") == 0)
		lst->str = ft_modhh(lst, type_list);
	else if (ft_strcmp(lst->modificator, "l") == 0)
		lst->str = ft_itoa_ll((long int)type_list->type_int);
	else if (ft_strcmp(lst->modificator, "z") == 0)
		lst->str = ft_itoa_ll(type_list->type_int);
	else if (MODLL || MODJ)
		lst->str = ft_itoa_ll(type_list->type_int);
	lst->str = ft_fix_dec_accuracy(lst, vlst);
	if (flag == 1)
		vlst->accuracy_value = -1;
	return (lst->str);
}
