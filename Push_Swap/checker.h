/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:31:25 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/17 15:48:39 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define ARR t_arr **arr_a, t_arr **arr_b
# define ISDGT ft_isdigit(str[i])
# define MINUSNUM ((ISDGT == 0 && str[i] == '-' && ft_isdigit(str[i + 1]) == 1))
# define SUBCAST (unsigned int)(i + 1)
# define SUBEDGES SUBCAST, (unsigned int)ft_strlen(str) - SUBCAST
# define C1 \e[32m
# define C2 \e[33m
# define C3 \e[94m
# define C4 \e[91m

typedef struct			s_arr
{
	long int			nb;
	struct s_arr		*next;
	struct s_arr		*prev;
}						t_arr;

void					ft_run_normal_vc
						(int argc, char **argv, t_arr **arr_a, t_arr **arr_b);
void					ft_arrdel(t_arr **arr_a, t_arr **arr_b);
void					ft_get_data(t_arr **arr_a, char *str);
void					ft_create_elem(t_arr **arr_a, long long int nb);
void					ft_error(int err);
int						ft_ifnumber(char *str);
void					ft_strjoin_free(char **s1, char *s2);
void					ft_strsub_free
						(char **s, unsigned int start, unsigned int len);
void					ft_input_validation(t_arr **arr);
int						ft_lstlen(t_arr **arr);
void					ft_read_commands(t_arr **arr_a, t_arr **arr_b, int cl);
void					ft_read_commands_dbg(t_arr **arr_a, t_arr **arr_b);
void					ft_print_arr(t_arr **arr_a, t_arr **arr_b);
int						ft_get_command
						(char	**str, t_arr **arr_a, t_arr **arr_b);
void					ft_check_sorted
						(t_arr **arr_a, t_arr **arr_b, int op, int o);
void					ft_goto_start(t_arr **arr);
void					ft_goto_end(t_arr **arr);
void					ft_sa(t_arr **arr_a, t_arr **arr_b);
void					ft_sb(t_arr **arr_a, t_arr **arr_b);
void					ft_ss(t_arr **arr_a, t_arr **arr_b);
void					ft_pa(t_arr **arr_a, t_arr **arr_b);
void					ft_pb(t_arr **arr_a, t_arr **arr_b);
void					ft_ra(t_arr **arr_a, t_arr **arr_b);
void					ft_rb(t_arr **arr_a, t_arr **arr_b);
void					ft_rr(t_arr **arr_a, t_arr **arr_b);
void					ft_rra(t_arr **arr_a, t_arr **arr_b);
void					ft_rrb(t_arr **arr_a, t_arr **arr_b);
void					ft_rrr(t_arr **arr_a, t_arr **arr_b);
void					ft_run_normal_lc
						(int argc, char **argv, t_arr **arr_a, t_arr **arr_b);
void					ft_run_normal_l
						(int argc, char **argv, t_arr **arr_a, t_arr **arr_b);

#endif
