/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:17:34 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:39:23 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_revstr(char **str, t_lst *lst)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = ft_strlen(*str) - 1;
	while (i < k)
	{
		ft_swap_char(&(*str)[i], &(*str)[k]);
		i++;
		k--;
	}
	i = 0;
	if (lst->type == 'X')
		while ((*str)[i] != '\0')
		{
			(*str)[i] = ft_toupper((*str)[i]);
			i++;
		}
}

static char	*ft_devide(unsigned long long int nb, char *num)
{
	char	*tmp;

	tmp = NULL;
	while (nb != 0)
		if (nb % 16 < 10)
		{
			tmp = num;
			num = ft_joinchar(num, *ft_itoa_ll((long long int)(nb % 16)));
			free(tmp);
			tmp = NULL;
			nb = nb / 16;
		}
		else
		{
			tmp = num;
			num = ft_joinchar(num, (nb % 16) + 87);
			free(tmp);
			tmp = NULL;
			nb = nb / 16;
		}
	return (num);
}

void		*ft_make_hex(unsigned long long int nb, t_lst *lst)
{
	char	*num;
	int		i;

	i = 0;
	num = (char *)malloc(sizeof(char));
	if (nb == 0 && (ZEROACC) && ft_strchr(lst->arg, '.') != NULL)
		return ("\0");
	if (nb == 0)
		return ("0");
	num = ft_devide(nb, num);
	ft_revstr(&num, lst);
	return (num);
}

void		*ft_make_eightsys(unsigned long long int nb, t_lst *lst)
{
	char	*num;
	char	*tmp;
	int		i;

	i = 0;
	if (nb == 0 && (ZEROACC) && ISP && ft_strchr(lst->arg, '#') == NULL)
		return ("\0");
	if (nb == 0)
		return ("0");
	num = (char *)malloc(sizeof(char));
	while (nb != 0)
	{
		tmp = num;
		num = ft_joinchar(num, *ft_itoa_ull((unsigned long long int)(nb % 8)));
		free(tmp);
		tmp = NULL;
		nb = nb / 8;
	}
	ft_revstr(&num, lst);
	return (num);
}
