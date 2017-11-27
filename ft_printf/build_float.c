/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:44:10 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:38:31 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double	ft_cut_number(double nb, char **n)
{
	static int	flag = 0;

	if (flag == 0)
	{
		nb = nb - (long long int)nb;
		flag = 1;
	}
	nb = nb * 10;
	*n = ft_strjoin(*n, ft_itoa_ll((long long int)nb));
	nb = nb - (long long int)nb;
	if (nb == 0)
		flag = 0;
	return (nb);
}

static char		*ft_iter_both(char *n, char *int_part)
{
	int		i;

	i = -1;
	while (n[++i] != '\0')
		n[i] = '0';
	int_part = ft_numiter(int_part);
	return (int_part);
}

char			*ft_fix_accuracy(char *str, t_value *vlst)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '.')
	{
		len = ft_strlen(&str[i]);
		if ((int)len <= vlst->accuracy_value)
			while ((int)len++ <= vlst->accuracy_value)
				str = ft_joinchar(str, '0');
	}
	return (str);
}

static char		*ft_get_float_part(char *n, char *int_part,\
									t_value *vlst, t_lst *lst)
{
	int		i;

	i = 0;
	if (vlst->accuracy_value == 0 && ABSZER)
		return ("0");
	n = ft_strsub(n, 0, (size_t)(vlst->accuracy_value + 1));
	if (n[vlst->accuracy_value] > '4' && LENACC)
	{
		n = ft_strsub(n, 0, (size_t)(vlst->accuracy_value));
		if (ft_order_compare(n) == 1)
			n = ft_numiter(n);
		else
			int_part = ft_iter_both(n, int_part);
	}
	else
		n = ft_strsub(n, 0, (size_t)(vlst->accuracy_value));
	lst->str = ft_strdup(int_part);
	if (vlst->accuracy_value > 0)
	{
		while (lst->str[i] != '\0')
			i++;
		lst->str[i] = '.';
		lst->str = ft_strjoin(lst->str, n);
	}
	return (lst->str);
}

char			*ft_make_float(t_lst *lst, double nb, t_value *vlst)
{
	double			num;
	char			*n;
	char			*int_part;

	num = nb;
	if (vlst->accuracy_value == -1)
		vlst->accuracy_value = 6;
	lst->str = ft_itoa_ll((long long int)nb);
	int_part = ft_itoa_ll((long long int)nb);
	nb = nb - (int)nb;
	nb = nb < 0 ? -nb : nb;
	n = (char *)malloc(sizeof(char));
	while (nb != 0)
		nb = ft_cut_number(nb, &n);
	if (vlst->accuracy_value == 0 && ft_strlen(n) == 1 && n[0] == '5')
	{
		if (ft_atoi_ll(int_part) % 2 == 0)
			return (int_part);
		if (ft_atoi_ll(int_part) % 2 != 0)
			return (ft_itoa_ll(ft_atoi_ll(int_part) + 1));
	}
	lst->str = ft_get_float_part(n, int_part, vlst, lst);
	if (num < 0 && num > -1 && int_part[0] == '0')
		lst->str = ft_strjoin("-", lst->str);
	return (ft_fix_accuracy(lst->str, vlst));
}
