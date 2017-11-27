/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:56:51 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/17 15:42:19 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_read_commands_dbg(t_arr **arr_a, t_arr **arr_b)
{
	char	*buf;
	int		rd;
	char	*str;

	buf = (char *)malloc(sizeof(char));
	str = (char *)malloc(sizeof(char));
	while ((rd = (int)read(0, buf, 1)) != EOF && buf[0] != ' ' && rd != 0)
	{
		ft_strjoin_free(&str, buf);
		ft_get_command(&str, arr_a, arr_b);
		if (str[ft_strlen(str) - 1] == '\n')
			ft_strsub_free(&str, 0, 0);
	}
	free(buf);
	free(str);
}

static int	ft_iter_i(unsigned int i, char *buf)
{
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i);
}

static int	ft_free_rd(char **a, char **b, int op)
{
	free(*a);
	free(*b);
	return (op);
}

static int	ft_wtf(int *len, int *i, char **str, char **buf)
{
	int		k;

	k = 0;
	while (read(0, (*buf) + (*i), 1) != 0 && (*buf)[*i] != EOF)
		(*i)++;
	*len = (unsigned int)ft_strlen(*buf);
	*i = ft_iter_i(*i, *buf);
	*str = ft_strsub(*buf, 0, *i);
	ft_strsub_free(buf, (unsigned int)(*i + 1), *len);
	return (1);
}

int			ft_read_commands(t_arr **a_a, t_arr **a_b, int cl)
{
	char		*buf;
	char		*str;
	static int	i = 0;
	int			len;
	static int	op = 0;

	buf = (char *)malloc(sizeof(char) * 100000000);
	ft_wtf(&len, &i, &str, &buf);
	while (ft_get_command(&str, a_a, a_b) != 0 && ++op > -1 && buf[0] != '\0')
	{
		if (cl == 1)
			ft_print_arr(a_a, a_b);
		i = ft_iter_i(i, buf);
		free(str);
		str = ft_strsub(buf, 0, i);
		ft_strsub_free(&buf, (unsigned int)(i + 1), len);
	}
	if (cl == 1 || cl == 2)
		ft_print_arr(a_a, a_b);
	if (buf[0] != '\0' || str[0] != '\0')
		ft_error(8);
	return (ft_free_rd(&str, &buf, op));
}
