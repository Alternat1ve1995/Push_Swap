/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:25:28 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:39:28 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_numiter(char *str)
{
	int		k;
	char	*s;
	char	*number;

	s = ft_strdup(str);
	k = (int)ft_strlen(str) - 1;
	number = NULL;
	while (k != -1)
		if (s[k] < '9')
		{
			s[k] = s[k] + 1;
			break ;
		}
		else if (s[k] == '9')
		{
			s[k] = '0';
			k--;
		}
	if (k == -1)
		number = ft_strnew(ft_strlen(s) + 1);
	if (k == -1)
		number = ft_strjoin(ft_strdup("1"), s);
	else
		number = ft_strdup(s);
	return (number);
}

int					ft_order_compare(char *number)
{
	char	*num1;
	char	*num2;

	num1 = ft_strdup(number);
	num2 = ft_numiter(num1);
	if (ft_strlen(num1) == ft_strlen(num2))
		return (1);
	return (0);
}

char				*ft_fix_dec_accuracy(t_lst *lst, t_value *vlst)
{
	size_t	len;
	int		i;
	char	*str;

	str = "\0";
	i = -1;
	len = ft_strlen(lst->str);
	if (len <= (size_t)vlst->accuracy_value)
	{
		while (++i < (int)vlst->accuracy_value - (int)len)
			str = ft_joinchar(str, '0');
		if (lst->str[0] != '-')
			lst->str = ft_strjoin(str, lst->str);
		else
			lst->str = ft_strjoin(MOVEMINUS);
	}
	return (lst->str);
}
