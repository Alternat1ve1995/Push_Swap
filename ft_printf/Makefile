# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 19:33:18 by dkovalen          #+#    #+#              #
#    Updated: 2017/03/17 14:11:38 by vboiko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a

NAME2 = ./libft/libft.a

CC =				gcc
FLAGS =				-Wall -Werror -Wextra

PRINTF_SRC_DIR =	./printf

PRINTF_SRC_HEADER =	./ft_printf.h -I ./libft/includes/libft.h

PRINTF_COMPILED = num_hex.o build_expon.o build_grading.o build_types.o \
					build.o ft_printf.o itoa_ll.o number_make.o parser.o \
					width.o build_float.o make_dec.o ft_build_wid.o \
					ft_itoa_ullmax.o ft_make_dec.o make_symbs.o assistances.o \
					ft_putcolor.o



SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
    libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memalloc.c libft/ft_memccpy.c \
    libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c \
    libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c \
    libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_strcat.c \
    libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c \
    libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c \
    libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c \
    libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c \
    libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_tolower.c libft/ft_toupper.c \
    libft/ft_lstnew.c libft/ft_lstadd.c libft/ft_lstiter.c libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstmap.c \
    libft/ft_revsort_char.c libft/ft_sort_char.c libft/ft_swap_char.c libft/ft_swap_int.c\

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(PRINTF_COMPILED)
	make -C ./libft
	ar rc $(NAME) $(PRINTF_COMPILED) $(OBJ)
	ranlib $(NAME)

$(PRINTF_COMPILED): %.o: %.c
	$(CC) -c $(FLAGS) -I $(PRINTF_SRC_HEADER) -o $@ $<

clean:
	make clean -C ./libft
	rm -f $(PRINTF_COMPILED)

fclean: clean
	@-/bin/rm -f $(NAME2)
	@-/bin/rm -f $(NAME)

re: fclean all
