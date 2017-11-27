/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:40:15 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:12:53 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "checker.h"

# define NN next->next
# define N next
# define NLNN (*a)->N->nb < (*a)->NN->nb
# define NMNN (*a)->N->nb > (*a)->NN->nb
# define ARA *arr_a
# define ARB *arr_b
# define AA t_arr **arr_a
# define AB t_arr **arr_b
# define ARRR t_arr **a_a, t_arr **a_b
# define M (ARA)->NN->nb
# define R (ARA)->nb
# define FUCK ((*arr_b) != NULL && (*arr_b)->next != NULL)
# define NORME ((*arr_b)->nb < (*arr_b)->next->nb)
# define E1 (*a)->nb
# define E2 (*a)->next->nb
# define E3 (*a)->next->next->nb

typedef struct		s_elems
{
	int				top;
	int				bot;
	struct s_elems	*next;
	struct s_elems	*prev;
}					t_elems;

void				ft_run_sorting
					(t_arr **arr_a, t_arr **arr_b);
void				ft_first_sort
					(t_arr **arr_a, t_arr **arr_b, t_arr **parts);
void				ft_sort_two_elems
					(t_arr **arr_a, t_arr **arr_b);
void				ft_elemdel
					(t_arr **arr);
void				ft_sort_int_tab
					(int **tab, int len);
void				ft_ecm
					(char *str, void (*f)(t_arr**, t_arr**),
						t_arr **a_a, t_arr **a_b);
void				ft_push_sort
					(t_arr **arr_a, t_arr **arr_b, t_arr **elems);
void				ft_revpush_sort
					(t_arr **arr_a, t_arr **arr_b, t_arr **elems);
void				ft_divide_a
					(t_arr **a_a, t_arr **a_b, t_elems **elems,
						int new_elems[]);
void				ft_lstgoto_start
					(t_elems **arr);
void				ft_lstgoto_end
					(t_elems **arr);
void				ft_move_parts
					(t_arr **parts, t_elems **elems);
void				ft_lstelemdel
					(t_elems **elems);
void				ft_create_lstelem
					(t_elems **elems, int top, int bot);
void				ft_sort_tree_elems
					(t_arr **a, t_arr **b);
void				ft_gc
					(t_arr **a, t_arr **b, int i);
void				ft_fdiv
					(t_arr **arr_a, t_arr **arr_b, t_arr **parts, int *elems);
int					ft_find_median
					(t_arr **arr, int elems);
int					ft_is_needed_to_rotate
					(t_arr **arr, int elems, int median);
int					ft_qsort_tree
					(t_arr **arr_a, t_arr **arr_b);
int					ft_help_qsort
					(t_arr **arr_a, t_arr **arr_b, t_arr **elems);
int					ft_div_b
					(t_arr **arr_a, t_arr **arr_b, t_elems **elems);
int					ft_is_needed_to_rotate_b
					(t_arr **arr, int elems, int median);
int					ft_is_needed_to_revrotate_b
					(t_arr **arr, int elems, int median);
int					ft_if_sorted(t_arr **arr_a, t_arr **arr_b);
int					ft_is_needed_to_revrotate_b
					(t_arr **arr, int elems, int median);
int					ft_if_sorted(t_arr **arr_a, t_arr **arr_b);
int					ft_find_div_median
					(t_arr **arr_b, t_elems **elems, int len);
int					ft_revrot_b
					(t_arr **arr_b, int **arr, int *i);
int					ft_get_from_bot
					(t_arr **arr_a, t_arr **arr_b, t_elems **elems, int median);
int					ft_get_from_top
					(t_arr **arr_a, t_arr **arr_b, t_elems **elems, int median);
int					ft_precheck
					(t_arr **a_a, t_arr **a_b, t_elems **elems, int *new_elems);
int					ft_fuck_the_norm
					(t_arr **arr_a, t_arr **arr_b, int p_e, int median);
int					ft_is_needed_to_rotate_top_a
					(t_arr **arr, int elems, int median);
int					ft_is_needed_to_rotate_bot_a
					(t_arr **arr, int elems, int median);
int					ft_find_md_a
					(t_arr **arr_a, int el[]);
void				ft_check_recursion
					(t_arr **a_a, t_arr **a_b, t_elems **elems, int **n_e);
int					ft_i_love_norme(t_arr **arr);

#endif
