/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:01:26 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/19 16:01:43 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_do_len(t_lst lst, size_t ln, t_type type_list)
{
	ln = ln + ft_strlen(lst.str);
	if (lst.str[0] == '\0' && type_list.type_string == NULL && NNF)
		ln++;
	if (lst.type == 'c' && type_list.type_char == 0)
		ln++;
	return (ln);
}

static void		ft_ifpercent(int *ln, int *i)
{
	ft_putchar('%');
	(*ln)++;
	(*i)++;
}

static void		ft_ifsym(char c, int *ln)
{
	ft_putchar(c);
	(*ln)++;
}

static int		start_print(char *str, va_list *ap, int i, int ln)
{
	t_type		type_list;
	t_lst		lst;
	t_value		vlst;

	while (str[++i] != '\0')
		if (str[i] == '{' && str[i + 1] != '%')
			i = ft_putcolor(i, str);
		else if (str[i] == '%')
			if (str[i + 1] == '%')
				ft_ifpercent(&ln, &i);
			else if (str[i + 1] == '\0')
				ft_putchar('\0');
			else
			{
				ft_nulllst(&vlst, &lst, &type_list);
				lst.type = str[ft_modlen(str, i)];
				lst.arg = ft_strsub(str, (UI)(i + 1), (S)ft_modlen(str, i) - i);
				ft_pars(&type_list, &vlst, &lst, ap);
				ft_builder(&type_list, &lst, &vlst);
				i = ft_modlen(str, i);
				ln = ft_do_len(lst, ln, type_list);
			}
		else
			ft_ifsym(str[i], &ln);
	return (LAST ? 0 : ln);
}

int				ft_printf(char *str, ...)
{
	va_list		ap;
	int			ln;

	ln = 0;
	va_start(ap, str);
	ln = start_print(str, &ap, -1, 0);
	va_end(ap);
	return (ln);
}
