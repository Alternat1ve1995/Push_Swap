/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:56:51 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/17 15:49:29 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_strdestroy(char **str)
{
	ft_strsub_free(str, 0, 0);
	ft_memdel((void *)str);
}

void	ft_read_commands_dbg(t_arr **arr_a, t_arr **arr_b)
{
	char	*buf;
	int		rd;
	char	*str;
	int		executed;

	buf = (char *)malloc(sizeof(char));
	str = (char *)malloc(sizeof(char));
	while ((rd = (int)read(0, buf, 1)) != EOF && buf[0] != ' ' && rd != 0)
	{
		ft_strjoin_free(&str, buf);
		executed = ft_get_command(&str, arr_a, arr_b);
		if (str[ft_strlen(str) - 1] == '\n')
		{
			ft_strsub_free(&str, 0, 0);
			if (executed == 0)
				ft_printf("error\nunknown command\n");
		}
	}
	free(buf);
	free(str);
}
