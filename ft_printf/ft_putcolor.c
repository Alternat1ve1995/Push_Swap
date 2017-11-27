/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:48:45 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/19 15:54:33 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_colors(char *color)
{
	if (ft_strcmp(color, "C_RED") == 0)
		write(1, "\e[31m", 5);
	else if (ft_strcmp(color, "C_GREEN") == 0)
		write(1, "\e[32m", 5);
	else if (ft_strcmp(color, "C_YELLOW") == 0)
		write(1, "\e[33m", 5);
	else if (ft_strcmp(color, "C_BLUE") == 0)
		write(1, "\e[34m", 5);
	else if (ft_strcmp(color, "C_MAGENTA") == 0)
		write(1, "\e[35m", 5);
	else if (ft_strcmp(color, "C_CYAN") == 0)
		write(1, "\e[36m", 5);
	else if (ft_strcmp(color, "C_DGRAY") == 0)
		write(1, "\e[90m", 5);
	else if (ft_strcmp(color, "C_LRED") == 0)
		write(1, "\e[91m", 5);
	else if (ft_strcmp(color, "C_LGREEN") == 0)
		write(1, "\e[92m", 5);
	else if (ft_strcmp(color, "C_LYELLOW") == 0)
		write(1, "\e[93m", 5);
	else if (ft_strcmp(color, "C_LBLUE") == 0)
		write(1, "\e[94m", 5);
	else
		return (0);
	return (1);
}

static int		ft_text(char *color)
{
	if (ft_strcmp(color, "T_BOLD") == 0)
		write(1, "\e[1m", 4);
	else if (ft_strcmp(color, "T_UNDERLINED") == 0)
		write(1, "\e[4m", 4);
	else
		return (0);
	return (1);
}

static int		ft_apply_mods(char *color, char *str, int i, int k)
{
	int		col;

	col = 1;
	color = ft_strsub(str, i + 1, k - i - 1);
	if (color[0] == 'C' && color[1] == '_')
		col = ft_colors(color);
	else if (color[0] == 'T' && color[1] == '_')
		col = ft_text(color);
	else if (ft_strcmp(color, "EOM") == 0)
	{
		write(1, "\e[0m", 4);
		write(1, "\e[39m", 5);
		write(1, "\e[24m", 5);
		col = 1;
	}
	else
		col = 0;
	return (col);
}

int				ft_putcolor(int i, char *str)
{
	int		k;
	char	*color;
	int		col;

	k = i;
	col = 0;
	color = NULL;
	while (str[k] != '}' && str[k] != '\0')
		k++;
	if (str[k] == '}')
		col = ft_apply_mods(color, str, i, k);
	else
		col = 0;
	if (col == 0)
	{
		ft_putchar('{');
		return (i);
	}
	return (k);
}
