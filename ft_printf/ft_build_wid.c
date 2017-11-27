/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_wid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:48:48 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:38:47 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_addition_kostil(t_lst *lst, int i)
{
	if (lst->str[i] == 'x' || lst->str[i] == 'X')
		while (i != 1)
		{
			ft_swap_char(&lst->str[i], &lst->str[i - 1]);
			i--;
		}
	else
		while (i != 0)
		{
			ft_swap_char(&lst->str[i], &lst->str[i - 1]);
			i--;
		}
}

static char	*ft_addition_one(t_lst *lst, t_value *vlst, t_type *type_list)
{
	int		i;
	char	*str;
	size_t	len;

	i = -1;
	len = ft_strlen(lst->str);
	str = ft_strdup("\0");
	if (lst->type == 'c' && type_list->type_char == 0)
		vlst->width_value--;
	while (++i < (int)(vlst->width_value - len))
		str = ft_joinchar(str, '0');
	lst->str = ft_strjoin(str, lst->str);
	i = 0;
	while (lst->str[i] != '-' && lst->str[i] != '+' && lst->str[i] != 'x' &&
			lst->str[i] != 'X' && lst->str[i] != ' ' && lst->str[i] != '\0')
		i++;
	if (lst->str[i] != '\0')
		ft_addition_kostil(lst, i);
	return (lst->str);
}

static char	*ft_addition_two(t_lst *lst, t_value *vlst, t_type *type_list)
{
	int		i;
	char	*str;
	size_t	len;

	i = -1;
	len = ft_strlen(lst->str);
	str = ft_strdup("\0");
	if (lst->type == 'c' && type_list->type_char == 0)
		len++;
	while (++i < (int)(vlst->width_value - len))
		str = ft_joinchar(str, ' ');
	lst->str = ft_strjoin(str, lst->str);
	return (lst->str);
}

static char	*ft_addition_three(t_lst *lst, t_value *vlst)
{
	int		i;
	char	*str;
	size_t	len;

	i = -1;
	len = ft_strlen(lst->str);
	str = ft_strdup("\0");
	while (++i < (int)(vlst->width_value - len))
		str = ft_joinchar(str, ' ');
	lst->str = ft_strjoin(lst->str, str);
	return (lst->str);
}

char		*ft_build_wid(t_lst *lst, t_value *vlst, t_type *type_list)
{
	if (ft_strlen(lst->str) < (size_t)vlst->width_value)
	{
		if ((ft_strchr(lst->flag, '0') != NULL &&
				ft_strchr(lst->flag, '-') == NULL) &&
				(vlst->accuracy_value == -1 &&
						!(LT == 'x' && LT == 'X' && LT == 'd'
							&& LT == 'i' && LT == 'o')))
			lst->str = ft_addition_one(lst, vlst, type_list);
		else if (ft_strchr(lst->flag, '-') == NULL)
			lst->str = ft_addition_two(lst, vlst, type_list);
		else if (ft_strchr(lst->flag, '-') != NULL)
			lst->str = ft_addition_three(lst, vlst);
	}
	return (lst->str);
}
