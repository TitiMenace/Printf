# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschecro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 02:48:07 by tschecro          #+#    #+#              #
#    Updated: 2022/12/11 11:00:49 by tschecro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	./print_args.c ./fb_casual.c ./fb_minus.c ./flags_fonction.c \
			./ft_printf.c ./printf_utils.c ./get_len.c ./fill_buffer.c \
			./define_args.c ./fb_zero.c ./check_width.c

HEADER		= 	ft_printf.h

OBJ		=	$(SRC:.c=.o)

NAME		=	libprintf.a	

CC		=	cc

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			ar rc $(NAME) $(OBJ)
			@echo "\033[1;32m\nDone!\033[0m"

%.o		:	%.c $(HEADER)
			@printf "\033[0;33mGenerating libft object... %-38.38s \r" $@
			@$(CC) -Wall -Wextra -Werror -c $< -o $@

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

bonus		:	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "\033[1;32m\nDone!\033[0m"

.PHONY		:	all clean fclean re
		

