/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:32:05 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:39:32 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pars_width(t_lst *lst, va_list *ap, int i)
{
	if (lst->arg[i] == '*')
	{
		lst->width = ft_itoa(va_arg(*ap, int));
		if (lst->width[0] == '-')
		{
			lst->width = ft_strsub(lst->width, 1, ft_strlen(lst->width) - 1);
			lst->flag = ft_joinchar(lst->flag, '-');
		}
	}
	else
	{
		i = ft_rdwidth(lst, i);
	}
	return (i);
}

static int	ft_pars_accuracy(t_lst *lst, t_value *vlst, va_list *ap, int i)
{
	if (lst->arg[i + 1] == '*')
		i = ft_get_accuracy(vlst, ap, i);
	else if (lst->arg[i + 1] > 47 && lst->arg[i + 1] < 58)
		i = ft_rdaccuracy(lst, i + 1);
	else
		lst->accuracy = ft_strdup("0");
	return (i);
}

static void	ft_select_values(t_value *vlst, t_lst *lst)
{
	if (lst->width[0] != '\0')
		vlst->width_value = ft_atoi(lst->width);
	if (lst->accuracy[0] != '\0')
		vlst->accuracy_value = ft_atoi(lst->accuracy);
}

void		ft_pars(t_type *type_list, t_value *vlst, t_lst *lst, va_list *ap)
{
	int		i;

	i = 0;
	if (ft_strchr(FRIENDLYSYMB, TYPE) != NULL && ft_strchr(SPEC, TYPE) == NULL)
		return ;
	while (lst->arg[i] != '\0')
	{
		if (FLAG)
			lst->flag = ft_joinchar(lst->flag, lst->arg[i]);
		else if (lst->arg[i] == '*' || (IF_NUM))
			i = ft_pars_width(lst, ap, i);
		else if (lst->arg[i] == '.')
			i = ft_pars_accuracy(lst, vlst, ap, i);
		else if (ft_strchr(MODS, lst->arg[i]))
			i = ft_detect_modificator(lst, i);
		i++;
	}
	ft_select_values(vlst, lst);
	ft_get_type(type_list, lst, ap);
}
