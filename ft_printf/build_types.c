/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:51:25 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:38:42 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_build_type(t_type *type_list, t_lst *lst, t_value *vlst)
{
	if (TYPE == 'd' || TYPE == 'i' || TYPE == 'D')
		lst->str = ft_make_accdec(lst, vlst, type_list);
	else if (TYPE == 'c' || TYPE == 'C')
		lst->str = ft_make_char(lst, type_list);
	else if (TYPE == 's' || TYPE == 'S')
		lst->str = ft_make_string(lst, vlst, type_list);
	else if (TYPE == 'u')
		lst->str = ft_make_accunsigned(lst, vlst, type_list);
	else if (TYPE == 'U')
		lst->str = ft_make_accmaxunsigned(lst, vlst, type_list);
	else if (TYPE == 'X' || TYPE == 'x')
		lst->str = ft_make_acchex(lst, vlst, type_list);
	else if (TYPE == 'f' || TYPE == 'F')
		lst->str = ft_make_float(lst, type_list->type_double, vlst);
	else if (TYPE == 'e' || TYPE == 'E')
		lst->str = ft_make_expon(type_list, lst, vlst);
	else if (TYPE == 'g' || TYPE == 'G')
		lst->str = ft_build_grading(lst, vlst, type_list);
	else if (TYPE == 'p')
		lst->str = ft_print_pointer((LLI)type_list->type_int, lst, vlst);
	else if (TYPE == 'o' || TYPE == 'O')
		lst->str = ft_make_acceightsys(lst, vlst, type_list);
}

static char	*ft_flagife(t_lst *lst, int i)
{
	lst->str = ft_joinchar(lst->str, '.');
	while (lst->str[i] != '.')
		i++;
	while (lst->str[i + 1] != 'E' && lst->str[i + 1] != 'e')
	{
		ft_swap_char(&lst->str[i], &lst->str[i - 1]);
		i--;
	}
	return (lst->str);
}

void		ft_build_flag(t_lst *lst, t_value *vlst, t_type *type_list)
{
	int		i;

	i = 0;
	vlst->accuracy_value = vlst->accuracy_value;
	if (ft_strchr(lst->flag, '+') != NULL && IFDEC)
		if (lst->str[0] != '-')
			lst->str = ft_strjoin("+", lst->str);
	if (ft_strchr(lst->flag, ' ') != NULL && PLUSDEC)
		if (lst->str[0] != '-')
			lst->str = ft_strjoin(" ", lst->str);
	if (ft_strchr(lst->flag, '#') != NULL)
	{
		if (TYPE == 'x' && ft_strcmp(lst->str, "0") != 0 && lst->str[0] != '\0')
			lst->str = ft_strjoin("0x", lst->str);
		else if (TYPE == 'X' && ft_strcmp(lst->str, "0") != 0)
			lst->str = ft_strjoin("0X", lst->str);
		else if ((TYPE == 'o' || TYPE == 'O') && type_list->type_unsigned != 0)
			lst->str = ft_strjoin("0", lst->str);
		else if ((TYPE == 'f' || TYPE == 'F') && vlst->accuracy_value == 0)
			lst->str = ft_joinchar(lst->str, '.');
		else if ((TYPE == 'e' || TYPE == 'E') && vlst->accuracy_value == 0)
			lst->str = ft_flagife(lst, i);
	}
}
