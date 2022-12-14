# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschecro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 01:52:49 by tschecro          #+#    #+#              #
#    Updated: 2023/01/06 22:55:37 by tschecro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	./print_args.c ./fb_casual.c ./fb_minus.c ./flags_fonction.c \
			./ft_printf.c ./printf_utils.c ./get_len.c ./fill_buffer.c \
			./define_args.c ./fb_zero.c ./check_width.c \
			./print_arg_utils.c ./flag_utils.c

HEADER	=	ft_printf.h

OBJ		=	$(SRC:.c=.o)

NAME	=	libftprintf.a	

CC		=	cc

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			ar rc $(NAME) $(OBJ)

%.o		:	%.c
			$(CC) -Wall -Wextra -Werror -g -c $< -o $@

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

bonus	:	all

.PHONY	:	all clean fclean re
