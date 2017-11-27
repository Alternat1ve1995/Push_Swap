/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ullmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:37:53 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:38:51 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_itoa_memmax(int neg, size_t len, uintmax_t nb, uintmax_t n)
{
	char	*fin;
	int		a;

	a = 0;
	while (nb >= 10)
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

char			*ft_itoa_ullmax(uintmax_t n)
{
	size_t			len;
	uintmax_t		nb;
	int				neg;
	char			*str;

	len = 1;
	neg = 0;
	nb = n;
	str = ft_itoa_memmax(neg, len, nb, n);
	if (str == NULL)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	return (str);
}
