/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:54:33 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/06 19:13:47 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isascii(int a)
{
	if (a >= 0 && a <= 0x7F)
		return (1);
	return (0);
}
