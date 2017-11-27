/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistances.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:00:50 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 20:01:36 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nulllst(t_value *vlst, t_lst *lst, t_type *type_list)
{
	lst->arg = NULL;
	lst->str = "\0";
	lst->flag = "\0";
	lst->width = "\0";
	lst->accuracy = "\0";
	lst->modificator = NULL;
	lst->type = 0;
	vlst->width_value = -1;
	vlst->accuracy_value = -1;
	type_list->type_int = -1;
	type_list->type_unsigned = 0;
	type_list->type_double = -1;
	type_list->type_string = NULL;
	type_list->type_char = '\0';
}

int		ft_modlen(char *str, int i)
{
	i++;
	while (ft_strchr(FRIENDLYSYMB, str[i]) != NULL && str[i] != '\0')
	{
		if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o')
			break ;
		if (str[i] == 'F' || str[i] == 'f' || str[i] == 'X' || str[i] == 'x')
			break ;
		if (str[i] == 'e' || str[i] == 'E' || str[i] == 'g' || str[i] == 'G')
			break ;
		if (str[i] == 'a' || str[i] == 'A' || str[i] == 'c' || str[i] == 's')
			break ;
		if (str[i] == 'S' || str[i] == 'p' || str[i] == 'n' || str[i] == 'C')
			break ;
		if (str[i] == 'U' || str[i] == 'O' || str[i] == 'D')
			break ;
		if (str[i + 1] == '%')
		{
			i++;
			break ;
		}
		i++;
	}
	if (str[i] == '\0')
		i--;
	return (i);
}
