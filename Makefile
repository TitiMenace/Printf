# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschecro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 02:48:07 by tschecro          #+#    #+#              #
#    Updated: 2022/11/19 03:13:55 by tschecro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = ft_printf

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft/
LIBFT_NAME = libft.a

$(NAME): $(OBJS)
    $(AR) $@ $<

$(OBJS): makelibft

%.o: %.c
    $(CC) $(CFLAGS) -c $< ${LIBFT_DIR}${LIBFT_NAME} -o $@

makelibft:
    cd ${LIBFT_DIR} && make

fcleanlibft:
    cd ${LIBFT_DIR} && make fclean

all: $(NAME)

clean: fcleanlibft
    rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
    rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
