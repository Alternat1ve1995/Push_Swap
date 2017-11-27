/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:53:05 by vboiko            #+#    #+#             */
/*   Updated: 2017/02/08 14:05:25 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_type(t_type *type_list, t_lst *lst, va_list *ap)
{
	if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D' || TYPE == 'p')
		type_list->type_int = va_arg(*ap, long long int);
	else if (TYPE == 'c')
		type_list->type_char = (char)va_arg(*ap, unsigned int);
	else if (TYPE == 'u')
		type_list->type_unsigned = va_arg(*ap, unsigned long long int);
	else if (TYPE == 'U')
		type_list->type_uintmax = va_arg(*ap, uintmax_t);
	else if (TYPE == 'f' || TYPE == 'F' || TYPE == 'e' || TYPE == 'E' ||
			TYPE == 'g' || TYPE == 'G' || TYPE == 'a' || TYPE == 'A')
		type_list->type_double = va_arg(*ap, double);
	else if (TYPE == 's')
		type_list->type_string = va_arg(*ap, char *);
	else if (TYPE == 'x' || TYPE == 'X' || TYPE == 'o' || TYPE == 'O')
		type_list->type_unsigned = va_arg(*ap, unsigned long long int);
	else if (TYPE == 'C')
		type_list->type_wchar = va_arg(*ap, wchar_t);
	else if (TYPE == 'S')
		type_list->type_wstring = va_arg(*ap, wchar_t *);
	else
	{
		lst->type = 'c';
		type_list->type_char = lst->arg[ft_strlen(lst->arg) - 1];
	}
}

void	ft_builder(t_type *type_list, t_lst *lst, t_value *vlst)
{
	if (ft_strchr(FRIENDLYSYMB, TYPE) != NULL && ft_strchr(SPEC, TYPE) == NULL)
		ft_putstr(lst->str);
	ft_build_type(type_list, lst, vlst);
	ft_build_flag(lst, vlst, type_list);
	lst->str = ft_build_wid(lst, vlst, type_list);
	ft_putstr(lst->str);
}
