/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2023/01/05 19:24:13 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef	unsigned long long int ull_int;

typedef	struct	s_help
{
	ull_int	temp;
	ull_int	checknull;
	int tempneg;
	int	count;
	int	len_arg;
	int precision;
	int	wfield;
	int precount;
}				t_help;

/* -------------------------------------------------------------------------- */
/*                           FILE = ./print_args.c                            */
/* -------------------------------------------------------------------------- */
void	ft_putnbr(unsigned int temp);
int	ft_putnstr(char *str, int n);
int	ft_print_args(const char *str, int j, unsigned long long int temp, int count);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./fb_casual.c                            */
/* -------------------------------------------------------------------------- */
int	fb_casual(va_list args, const char *str, int i, int j);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./fb_minus.c                             */
/* -------------------------------------------------------------------------- */
int	fb_minus(va_list args, int i, int j, const char *str);

/* -------------------------------------------------------------------------- */
/*                         FILE = ./flags_fonction.c                          */
/* -------------------------------------------------------------------------- */
int	check_flag_zero(int i, int j, const char *str);
int	check_flag_minus(int i, int j, const char *str);
int	check_flag_plus(int i, int j, const char *str);
int	check_flag_blank(int i, int j, const char *str);
int	check_flag_hashtag(int i, int j, const char *str);

/* -------------------------------------------------------------------------- */
/*                         FILE = ./print_arg_utils.c                         */
/* -------------------------------------------------------------------------- */
int	ft_putaddress(unsigned long long int temp);
int	ft_putnbr_hexa(unsigned int nb);
int	ft_putnbr_hexa_maj(unsigned int nb);
int	ft_put_hexa(const char *str, int j, unsigned long long int temp);

/* -------------------------------------------------------------------------- */
/*                          FILE = ./printf_utils.c                           */
/* -------------------------------------------------------------------------- */
int	ft_strcmp(char *s1, char *s2);
int	check_charset(char c, char *set);
int	ft_putstr(const char *str);
void	ft_putchar(char c);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./ft_printf.c                            */
/* -------------------------------------------------------------------------- */
void	init_parse(const char *str, int *i, int *count);
int	second_parse(int *j, const char *str);
int	ft_printf(const char *str, ...);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./flag_utils.c                            */
/* -------------------------------------------------------------------------- */
int	ft_count_flags(const char *str, int j, int i, unsigned long long int temp);
void ft_print_flags(const char *str, int j, int i, unsigned long long int temp);

/* -------------------------------------------------------------------------- */
/*                             FILE = ./get_len.c                             */
/* -------------------------------------------------------------------------- */
int	ft_strlen(char *str, int precision);
int	ft_hexa_len(unsigned long long int temp);
int	ft_nb_u_len(unsigned int n);
int	ft_nb_len(int n);
int	ft_get_len(unsigned long long int temp, int j, const char *str, int precision);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./fill_buffer.c                           */
/* -------------------------------------------------------------------------- */
int	fill_buffer(va_list args, int i, int j, const char *str);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./define_args.c                           */
/* -------------------------------------------------------------------------- */
int	define_negative(va_list args);
unsigned long long int	define_args(va_list args, int j, const char *str);

/* -------------------------------------------------------------------------- */
/*                             FILE = ./fb_zero.c                             */
/* -------------------------------------------------------------------------- */
int	fb_zero(va_list args, const char *str, int i, int j);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./check_width.c                           */
/* -------------------------------------------------------------------------- */
int	small_atoi(const char *str, int i);
int	check_precision(const char *str, int i, int j);
int	check_width_field(const char *str, int i, int j);


#endif
