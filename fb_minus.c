/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:44:13 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/06 02:13:38 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_helper_minus(const char *str, int i, int j, t_help *helper)
{
	helper->temp = 0;
	helper->checknull = (ull_int)"(null)";
	helper->tempneg = 0;
	helper->count = 0;
	helper->len_arg = 0;
	helper->precision = check_precision(str, i, j);
	helper->wfield = check_width_field(str, i, j);
	helper->precount = 0;
}

void	fill_margin_minus(const char *str, int j, t_help *helper)
{
	if (str[j] != 's')
	{
		while (helper->precount < helper->precision)
		{
			write(1, "0", 1);
			helper->precount++;
		}	
	}
	else
	{
		while (helper->precision >= 0 && helper->precision < helper->len_arg)
			helper->len_arg--;
	}
	helper->count += helper->precount;
	if (!(helper->temp == 0 && helper->precision == 0))
		ft_print_args(str, j, helper->temp, helper->len_arg);
	while (helper->count < helper->wfield)
	{
		write(1, " ", 1);
		helper->count++;
	}
}

void	check_negative(const char *str, int i, int j, t_help *helper)
{
	if (helper->tempneg < 0)
	{
		write(1, "-", 1);
		helper->count++;
		helper->temp = (ull_int) - helper->tempneg;
	}
	else
	{
		helper->count = ft_count_flags(str, j, i, helper->temp);
		ft_print_flags(str, j, i, helper->temp);
	}
}

int	fb_minus(va_list args, int i, int j, const char *str)
{
	t_help	helper;

	init_helper_minus(str, i, j, &helper);
	if (str[j] == 'd' || str[j] == 'i')
		helper.tempneg = define_negative(args);
	else
		helper.temp = define_args(args, j, str);
	if ((void *)helper.temp == 0 && str[j] == 'p')
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (str[j] == 'd' || str[j] == 'i')
		helper.temp = (ull_int)helper.tempneg;
	check_negative(str, i, j, &helper);
	if (!(helper.temp == 0 && helper.precision == 0))
		helper.len_arg = ft_get_len(helper.temp, j, str, helper.precision);
	helper.precount = helper.len_arg;
	fill_margin_minus(str, j, &helper);
	return ((int)helper.count);
}
