/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:08:26 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:39:15 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_make_accunsigned(t_lst *lst, t_value *vlst, t_type *type_list)
{
	if (type_list->type_unsigned == 0 && (ZEROACC) && ISP)
		return ("\0");
	if (lst->modificator == NULL)
		lst->str = ft_itoa_ull((unsigned int)type_list->type_unsigned);
	else if (ft_strcmp(lst->modificator, "h") == 0)
		lst->str = ft_itoa_ull((unsigned short int)type_list->type_unsigned);
	else if (ft_strcmp(lst->modificator, "hh") == 0)
		lst->str = ft_itoa_ull((unsigned char)type_list->type_unsigned);
	else if (ft_strcmp(lst->modificator, "l") == 0)
		lst->str = ft_itoa_ullmax((uintmax_t)type_list->type_unsigned);
	else if (ft_strcmp(lst->modificator, "ll") == 0)
		lst->str = ft_itoa_ullmax((ULL)type_list->type_unsigned);
	else if (ft_strcmp(lst->modificator, "j") == 0)
		lst->str = ft_itoa_ullmax((uintmax_t)type_list->type_unsigned);
	else if (ft_strcmp(lst->modificator, "z") == 0)
		lst->str = ft_itoa_ullmax((uintmax_t)type_list->type_unsigned);
	lst->str = ft_fix_dec_accuracy(lst, vlst);
	return (lst->str);
}

char	*ft_make_accmaxunsigned(t_lst *lst, t_value *vlst, t_type *type_list)
{
	if (lst->modificator == NULL)
	{
		if (lst->type == 'u')
			lst->str = ft_itoa_ull(type_list->type_uintmax);
		else if (lst->type == 'U')
			lst->str = ft_itoa_ullmax(type_list->type_uintmax);
	}
	else if (ft_strcmp(lst->modificator, "h") == 0)
		lst->str = ft_itoa_ull(type_list->type_uintmax);
	else if (ft_strcmp(lst->modificator, "hh") == 0)
	{
		if (lst->type == 'u')
			lst->str = ft_itoa_ull((unsigned char)type_list->type_uintmax);
		else if (lst->type == 'U')
			lst->str = ft_itoa_ull((wchar_t)type_list->type_uintmax);
	}
	else if (ft_strcmp(lst->modificator, "l") == 0)
		lst->str = ft_itoa_ull((unsigned long int)type_list->type_uintmax);
	else if (ft_strcmp(lst->modificator, "ll") == 0)
		lst->str = ft_itoa_ull((unsigned long long int)type_list->type_uintmax);
	else if (ft_strcmp(lst->modificator, "j") == 0)
		lst->str = ft_itoa_ull(type_list->type_uintmax);
	else if (ft_strcmp(lst->modificator, "z") == 0)
		lst->str = ft_itoa_ull(type_list->type_uintmax);
	return (ft_fix_dec_accuracy(lst, vlst));
}

char	*ft_make_acchex(t_lst *lst, t_value *vlst, t_type *type_list)
{
	if (lst->modificator == NULL)
		lst->str = ft_make_hex((unsigned int)type_list->type_unsigned, lst);
	else if (ft_strcmp(lst->modificator, "h") == 0)
		lst->str = ft_make_hex((USI)type_list->type_unsigned, lst);
	else if (ft_strcmp(lst->modificator, "hh") == 0)
		lst->str = ft_make_hex((unsigned char)type_list->type_unsigned, lst);
	else if (ft_strcmp(lst->modificator, "l") == 0)
		lst->str = ft_make_hex((ULI)type_list->type_unsigned, lst);
	else if (ft_strcmp(lst->modificator, "ll") == 0)
		lst->str = ft_make_hex(type_list->type_unsigned, lst);
	else if (MODJ || ft_strcmp(lst->modificator, "z") == 0)
		lst->str = ft_make_hex(type_list->type_unsigned, lst);
	lst->str = ft_fix_dec_accuracy(lst, vlst);
	return (lst->str);
}

char	*ft_make_acceightsys(t_lst *lst, t_value *vlst, t_type *type_list)
{
	if (lst->modificator == NULL)
	{
		if (lst->type == 'o')
			lst->str = ft_make_eightsys((UI)type_list->type_unsigned, lst);
		else if (lst->type == 'O')
			lst->str = ft_make_eightsys(type_list->type_unsigned, lst);
	}
	else if (ft_strcmp(lst->modificator, "h") == 0)
		lst->str = ft_make_eightsys((USI)type_list->type_unsigned, lst);
	else if (ft_strcmp(lst->modificator, "hh") == 0)
	{
		if (lst->type == 'o')
			lst->str = ft_make_eightsys((UC)type_list->type_unsigned, lst);
		else if (lst->type == 'O')
			lst->str = ft_make_eightsys((wchar_t)type_list->type_unsigned, lst);
	}
	else if (ft_strcmp(lst->modificator, "l") == 0)
		lst->str = ft_make_eightsys((ULI)type_list->type_unsigned, lst);
	else if (ft_strcmp(lst->modificator, "ll") == 0)
		lst->str = ft_make_eightsys((ULL)type_list->type_unsigned, lst);
	else if (ft_strcmp(lst->modificator, "j") == 0)
		lst->str = ft_make_eightsys((uintmax_t)type_list->type_unsigned, lst);
	else if (ft_strcmp(lst->modificator, "z") == 0)
		lst->str = ft_make_eightsys(type_list->type_unsigned, lst);
	return (lst->str = ft_fix_dec_accuracy(lst, vlst));
}
