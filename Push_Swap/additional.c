/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:36:58 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/17 15:28:18 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int err)
{
	if (err == 1 || err == 2 || err == 3 || err == 7)
		ft_printf("error\n");
	if (err == 1)
		ft_printf("array has duplicate numbers\n");
	else if (err == 2)
		ft_printf("some of array values may not be an integer\n");
	else if (err == 3)
		ft_printf("some of array values may not fit into type int\n");
	else if (err == 4)
		ft_printf("KO\narray <a> is not sorted\n");
	else if (err == 5)
		ft_printf("KO\narray <b> is not empty\n");
	else if (err == 6)
		ft_printf("KO\narray <a> is empty\n");
	printf("Exiting...\n");
	exit(-1);
}

int		ft_ifnumber(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 1 && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	ft_strjoin_free(char **s1, char *s2)
{
	char	*mem;

	mem = NULL;
	mem = ft_strjoin(*s1, s2);
	if (*s1)
		free(*s1);
	*s1 = mem;
}

void	ft_strsub_free(char **s, unsigned int start, unsigned int len)
{
	char	*mem;

	mem = NULL;
	mem = ft_strsub(*s, start, len);
	if (*s)
		free(*s);
	*s = mem;
}

int		ft_lstlen(t_arr **arr)
{
	int		len;

	len = 0;
	ft_goto_start(arr);
	if (*arr != NULL)
		len = 1;
	if (*arr != NULL)
		while ((*arr)->next != NULL)
		{
			*arr = (*arr)->next;
			len++;
		}
	ft_goto_start(arr);
	return (len);
}
