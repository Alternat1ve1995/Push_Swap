# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/13 18:33:03 by vboiko            #+#    #+#              #
#    Updated: 2017/05/13 19:18:22 by vboiko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

LIBRARY = ./ft_printf/libftprintf.a

CHECKER_C = Checker/additional.c Checker/check_arrays.c Checker/data_usage.c Checker/execute_commands.c \
			Checker/move_arr.c Checker/push.c Checker/read_commands.c Checker/reverse_rotate.c Checker/rotate.c Checker/swap.c \
			Checker/main.c 

PUSH_C = Push_Swap/additional.c Push_Swap/check_arrays.c Push_Swap/data_usage.c Push_Swap/div_a_add.c Push_Swap/divide_a.c Push_Swap/divide_b.c \
		Push_Swap/execute_commands.c Push_Swap/first_sorting.c Push_Swap/lst_usage.c Push_Swap/main.c Push_Swap/move_arr.c Push_Swap/print_cm.c \
		Push_Swap/push.c Push_Swap/qsort_elems.c Push_Swap/read_commands.c Push_Swap/reverse_rotate.c Push_Swap/rotate.c Push_Swap/sort.c \
		Push_Swap/sort_tab.c Push_Swap/swap.c Push_Swap/three_elems_cases.c

all: checker push

checker:
	@ make -C ./ft_printf
	gcc $(FLAGS) $(CHECKER_C) $(LIBRARY) -o checker

push:
	@ make -C ./ft_printf
	gcc $(FLAGS) $(PUSH_C) $(LIBRARY) -o push_swap

# %.o: %.c
# 	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	make clean -C ./ft_printf
	rm -f *.o

fclean: clean
	@rm -f checker push_swap $(LIBRARY)

re: fclean all
