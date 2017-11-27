/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:27:11 by vboiko            #+#    #+#             */
/*   Updated: 2016/12/06 19:15:07 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	mem = (char *)malloc(sizeof(char) * size);
	if (mem == NULL)
		return (NULL);
	size = size + 1;
	while (size > 0)
	{
		size--;
		mem[size] = '\0';
	}
	return (mem);
}
