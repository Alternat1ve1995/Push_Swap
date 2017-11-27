/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_symbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:09:40 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:39:19 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_make_string(t_lst *lst, t_value *vlst, t_type *type_list)
{
	if (TYPE == 's')
	{
		if (type_list->type_string != NULL)
			lst->str = ft_strdup((char *)type_list->type_string);
		else
			lst->str = "(null)";
	}
	else if (TYPE == 'S')
	{
		if (type_list->type_wstring == NULL)
			lst->str = ft_strdup("(null)");
		else
			lst->str = ft_strdup((char *)type_list->type_wstring);
	}
	if (vlst->accuracy_value == -1 && ft_strchr(lst->arg, '.') != NULL)
		vlst->accuracy_value = 0;
	if ((size_t)vlst->accuracy_value < ft_strlen(lst->str))
		lst->str = ft_strsub(lst->str, 0, (size_t)vlst->accuracy_value);
	return (lst->str);
}

char	*ft_make_char(t_lst *lst, t_type *type_list)
{
	if (TYPE == 'c')
	{
		if (type_list->type_int == 0)
			lst->str = "\0";
		else
			lst->str = ft_joinchar(lst->str, type_list->type_char);
	}
	else if (TYPE == 'C')
	{
		if (type_list->type_wchar == 0)
			lst->str = "\0";
		else
			lst->str = ft_joinchar(lst->str, (char)type_list->type_wchar);
	}
	return (lst->str);
}
