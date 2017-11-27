/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:34:52 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:39:10 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_itoa_mem(int neg, size_t len, LLI nb, long long int n)
{
	char	*fin;
	int		a;

	a = 0;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		len++;
	}
	if (neg == 1)
		len++;
	fin = ft_strnew(len);
	if (fin == NULL)
		return (NULL);
	nb = n;
	while (len > 0)
	{
		a = (int)(nb % 10);
		if (a < 0)
			a = -a;
		fin[--len] = a + 48;
		nb = nb / 10;
	}
	return (fin);
}

char			*ft_itoa_ll(long long int n)
{
	size_t				len;
	long long int		nb;
	int					neg;
	char				*str;

	len = 1;
	neg = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	str = ft_itoa_mem(neg, len, nb, n);
	if (str == NULL)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa_ull(unsigned long long int n)
{
	size_t						len;
	unsigned long long int		nb;
	int							neg;
	char						*str;

	len = 1;
	neg = 0;
	nb = n;
	str = ft_itoa_mem(neg, len, nb, n);
	if (str == NULL)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	return (str);
}

long long int	ft_atoi_ll(const char *str)
{
	size_t					i;
	long long int			negative;
	long long int			num;

	i = 0;
	negative = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + (int)str[i++] - 48;
	}
	if (negative == 1)
		return (-num);
	return (num);
}
