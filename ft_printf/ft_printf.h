/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:29:44 by vboiko            #+#    #+#             */
/*   Updated: 2017/03/16 19:39:04 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define Q ==
# define W ||
# define FRIENDLYSYMB "1234567890*DOUzj-+ #.hlLdiuoxXfFeEgaAcsSpn"
# define NOTFRIENDLYSYMB "xXodiuOc"
# define SPEC "sSpdDioOuUxXcCeEfF"
# define MODS "Llhjz"
# define S size_t
# define UI unsigned int
# define NNF ft_strchr(NOTFRIENDLYSYMB, lst.type) == NULL
# define IF_NUM lst->arg[i] > 47 && lst->arg[i] < 58
# define AE lst->arg[i]
# define ABS(X) (X >= 0) ? X : -X
# define FLAG AE == '-' || AE == '+' || AE == ' ' || AE == '#' || AE == '0'
# define TYPE lst->type
# define TFLOAT lst->type == 'f' || lst->type == 'F'
# define IFPAIR ft_atoi_ll(int_part) % 2 == 0 && ft_atoi_ll(int_part) != 0
# define GETMINUS ft_strsub(lst->str, 1, (size_t)vlst->accuracy_value)
# define MOVEMINUS "-", ft_strjoin(ft_joinchar(str, '0'), GETMINUS)
# define LT lst->type
# define IFFL LT Q 'f' W LT Q 'F' W LT Q 'e' W LT Q 'E' W LT Q 'g' W LT Q 'G'
# define IFDEC (LT == 'd' || LT == 'i' || IFFL)
# define ULL unsigned long long int
# define LLI long long int
# define USI unsigned short int
# define ULI unsigned long int
# define UC unsigned char
# define SRAV lst, type_list->type_double, vlst)), lst->type
# define A ft_joinchar(ft_strjoin(exp, ft_make_float(SRAV), '-'
# define B ft_joinchar(ft_strjoin(exp, ft_make_float(SRAV), '+'
# define ABSZER ft_atoi_ll(int_part) == 0 && n[0] == '5' && ft_strlen(n) == 1
# define LENACC (int)ft_strlen(n) >= vlst->accuracy_value
# define LISTS t_value *vlst, t_lst *lst
# define PLUSDEC ft_strchr(lst->flag, '+') == NULL && IFDEC
# define ZEROACC lst->accuracy[0] == '0' || lst->accuracy[0] == '\0'
# define ISP ft_strchr(lst->arg, '.') != NULL
# define MODLL ft_strcmp(lst->modificator, "ll") == 0
# define MODJ ft_strcmp(lst->modificator, "j") == 0
# define NOTSPEC ft_strchr(SPEC, lst.type) == NULL
# define LAST ft_strchr(FRIENDLYSYMB, lst.type) != NULL && NOTSPEC

# include <limits.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	char			*arg;
	char			*str;
	char			*flag;
	char			*width;
	char			*accuracy;
	char			*modificator;
	char			type;
}					t_lst;

typedef struct		s_value
{
	int				width_value;
	int				accuracy_value;
}					t_value;

typedef struct		s_type
{
	long long int	type_int;
	ULL				type_uint;
	char			type_char;
	ULL				type_unsigned;
	double			type_double;
	char			*type_string;
	uintmax_t		type_uintmax;
	wchar_t			*type_wstring;
	wchar_t			type_wchar;
}					t_type;

int					ft_printf(char *format, ...);
void				ft_pars
					(t_type *type_list, t_value *vlst, t_lst *lst, va_list *ap);
char				*ft_joinchar(char *str, char c);
int					ft_detect_modificator(t_lst *lst, int i);
int					ft_get_accuracy(t_value *vlst, va_list *ap, int i);
int					ft_rdwidth(t_lst *lst, int i);
int					ft_rdaccuracy(t_lst *lst, int i);
void				ft_get_type(t_type *type_list, t_lst *lst, va_list *ap);
void				ft_builder(t_type *type_list, t_lst *lst, t_value *vlst);
void				ft_build_type(t_type *type_list, t_lst *lst, t_value *vlst);
void				ft_build_mods
					(t_type *type_list, t_lst *lst, t_value *vlst, va_list *ap);
void				ft_build_acc
					(t_type *type_list, t_lst *lst, t_value *vlst, va_list *ap);
char				*ft_build_wid(t_lst *lst, t_value *vlst, t_type *type_list);
void				ft_build_flag(t_lst *lst, t_value *vlst, t_type *type_list);
char				*ft_itoa_ll(long long int n);
char				*ft_itoa_ull(unsigned long long int n);
char				*ft_make_float(t_lst *lst, double nb, t_value *vlst);
long long int		ft_atoi_ll(const char *str);
char				*ft_numiter(char *str);
int					ft_order_compare(char *number);
void				*ft_make_hex(unsigned long long int nb, t_lst *lst);
char				*ft_make_expon
					(t_type *type_list, t_lst *lst, t_value *vlst);
char				*ft_fix_accuracy(char *str, t_value *vlst);
char				*ft_build_grading
					(t_lst *lst, t_value *vlst, t_type *type_list);
char				*ft_print_pointer
					(long long int nb, t_lst *lst, t_value *vlst);
void				*ft_make_eightsys(unsigned long long int nb, t_lst *lst);
char				*ft_make_accdec
					(t_lst *lst, t_value *vlst, t_type *type_list);
char				*ft_fix_dec_accuracy(t_lst *lst, t_value *vlst);
char				*ft_make_accunsigned
					(t_lst *lst, t_value *vlst, t_type *type_list);
char				*ft_make_acchex
					(t_lst *lst, t_value *vlst, t_type *type_list);
char				*ft_make_acceightsys
					(t_lst *lst, t_value *vlst, t_type *type_list);
char				*ft_make_string
					(t_lst *lst, t_value *vlst, t_type *type_list);
char				*ft_make_accmaxunsigned
					(t_lst *lst, t_value *vlst, t_type *type_list);
char				*ft_itoa_ullmax(uintmax_t n);
char				*ft_make_char(t_lst *lst, t_type *type_list);
void				ft_nulllst(t_value *vlst, t_lst *lst, t_type *type_list);
int					ft_modlen(char *str, int i);
int					ft_putcolor(int i, char *str);

#endif
