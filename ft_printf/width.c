/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:05:08 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:39:35 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_detect_modificator(t_lst *lst, int i)
{
	if (lst->modificator != NULL && (ft_strcmp(lst->modificator, "z") == 0 ||
			ft_strcmp(lst->modificator, "j") == 0))
		return (i);
	if (lst->arg[i] == 'L')
		lst->modificator = "L";
	else if (lst->arg[i] == 'j')
		lst->modificator = "j";
	else if (lst->arg[i] == 'z')
		lst->modificator = "z";
	else if (lst->arg[i] == 'l' && lst->arg[i + 1] == 'l')
	{
		lst->modificator = ft_strsub(lst->arg, (unsigned int)i, 2);
		i++;
	}
	else if (lst->arg[i] == 'l' && lst->arg[i + 1] != 'l')
		lst->modificator = ft_strsub(lst->arg, (unsigned int)i, 1);
	else if (lst->arg[i] == 'h' && lst->arg[i + 1] == 'h')
	{
		lst->modificator = ft_strsub(lst->arg, (unsigned int)i, 2);
		i++;
	}
	else if (lst->arg[i] == 'h' && lst->arg[i + 1] != 'h')
		lst->modificator = ft_strsub(lst->arg, (unsigned int)i, 1);
	return (i);
}

char	*ft_joinchar(char *str, char c)
{
	char	*join;
	int		i;

	i = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i] != '\0')
	{
		join[i] = str[i];
		i++;
	}
	join[i] = c;
	i++;
	join[i] = '\0';
	return (join);
}

int		ft_get_accuracy(t_value *vlst, va_list *ap, int i)
{
	vlst->accuracy_value = va_arg(*ap, int);
	if (vlst->accuracy_value < 0)
		vlst->accuracy_value = -1;
	return (i + 1);
}

int		ft_rdwidth(t_lst *lst, int i)
{
	lst->width = "\0";
	while (IF_NUM)
	{
		lst->width = ft_joinchar(lst->width, lst->arg[i]);
		i++;
	}
	return (i - 1);
}

int		ft_rdaccuracy(t_lst *lst, int i)
{
	while (IF_NUM)
	{
		lst->accuracy = ft_joinchar(lst->accuracy, lst->arg[i]);
		i++;
	}
	return (i - 1);
}
