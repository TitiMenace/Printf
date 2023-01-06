/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:39:41 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/06 03:56:13 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_helper_zero(const char *str, int i, int j, t_help *helper)
{
	helper->temp = 0;
	helper->checknull = (t_ull_int)"(null)";
	helper->tempneg = 0;
	helper->count = 0;
	helper->len_arg = 0;
	helper->precision = check_precision(str, i, j);
	helper->wfield = check_width_field(str, i, j);
	helper->precount = 0;
}

void	no_precision(const char *str, int i, int j, t_help *helper)
{
	if (helper->tempneg < 0)
		write(1, "-", 1);
	else
		ft_print_flags(str, j, i, helper->temp);
	helper->count += helper->len_arg;
	while (helper->count < helper->wfield)
	{
		write(1, "0", 1);
		helper->count++;
	}
}

void	fill_precision(const char *str, int i, int j, t_help *helper)
{
	if (helper->temp == 0 && helper->precision == 0)
		helper->len_arg = 0;
	while (helper->len_arg < helper->precision)
		helper->len_arg++;
	helper->count += helper->len_arg;
	while (helper->count < helper->wfield)
	{
		write(1, " ", 1);
		helper->count++;
	}
	if (helper->tempneg < 0)
		write(1, "-", 1);
	else
		ft_print_flags(str, j, i, helper->temp);
	helper->len_arg = ft_get_len(helper->temp, j, str, helper->precision);
	while (helper->len_arg < helper->precision)
	{
		write(1, "0", 1);
		helper->len_arg++;
	}
}

void	flag_count(const char *str, int i, int j, t_help *helper)
{
	if (helper->tempneg < 0)
	{
		helper->count++;
		helper->temp = (t_ull_int) - helper->tempneg;
	}
	else
	{	
		if (!((helper->temp == 0 && helper->tempneg == 0)
				&& helper->precision == 0))
			helper->count = ft_count_flags(str, j, i, helper->temp);
	}
}

int	fb_zero(va_list args, const char *str, int i, int j)
{
	t_help	helper;

	init_helper_zero(str, i, j, &helper);
	if (str[j] == 'd' || str[j] == 'i')
		helper.tempneg = define_negative(args);
	else
		helper.temp = define_args(args, j, str);
	if (str[j] == 'd' || str[j] == 'i')
		helper.temp = (t_ull_int)helper.tempneg;
	flag_count(str, i, j, &helper);
	helper.len_arg = ft_get_len(helper.temp, j, str, helper.precision);
	if (helper.precision == -1)
		no_precision(str, i, j, &helper);
	else
		fill_precision(str, i, j, &helper);
	if (!(helper.temp == 0 && helper.precision == 0))
		ft_print_args(str, j, helper.temp, 0);
	return ((int)helper.count);
}
