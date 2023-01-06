/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_casual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:54:49 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/06 03:50:06 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_helper(const char *str, int i, int j, t_help *helper)
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

void	fill_margin(const char *str, int j, int i, t_help *helper)
{
	helper->count += helper->len_arg;
	helper->precount = helper->len_arg;
	while (helper->precount < helper->precision && helper->precision >= 0)
	{
		helper->precount++;
		helper->count++;
	}
	while (helper->count < helper->wfield)
	{
		write(1, " ", 1);
		helper->count++;
	}
	if (helper->tempneg < 0)
		write(1, "-", 1);
	else
		ft_print_flags(str, j, i, helper->temp);
	helper->precount = helper->len_arg;
	while (helper->precount < helper->precision && helper->precision >= 0)
	{
		write(1, "0", 1);
		helper->precount++;
	}
}

void	fill_field(const char *str, int j, int i, t_help *helper)
{
	if (!(helper->temp == 0 && helper->precision == 0))
		helper->len_arg = ft_get_len(helper->temp, j, str, helper->precision);
	if (str[j] != 's')
		fill_margin(str, j, i, helper);
	else
	{
		helper->count += helper->len_arg;
		while (helper->wfield >= 0 && helper->count < helper->wfield)
		{
			write(1, " ", 1);
			helper->count++;
		}
	}
}

int	fb_casual(va_list args, const char *str, int i, int j)
{
	t_help	helper;

	init_helper(str, i, j, &helper);
	if (str[j] == 'd' || str[j] == 'i')
		helper.tempneg = define_negative(args);
	else
		helper.temp = define_args(args, j, str);
	if (helper.temp == helper.checknull
		&& (helper.precision >= 0 && helper.precision < 6))
		return (0);
	if ((void *)helper.temp == 0 && str[j] == 'p')
		helper.temp = (t_ull_int)"(nil)";
	if (str[j] == 'd' || str[j] == 'i')
		helper.temp = (t_ull_int)helper.tempneg;
	if (helper.tempneg < 0)
	{
		helper.count++;
		helper.temp = (t_ull_int) - helper.tempneg;
	}
	else
		helper.count = ft_count_flags(str, j, i, helper.temp);
	fill_field(str, j, i, &helper);
	if (!(helper.temp == 0 && helper.precision == 0))
		ft_print_args(str, j, helper.temp, helper.len_arg);
	return ((int)helper.count);
}
