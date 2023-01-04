/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:39:41 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/04 17:57:41 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fb_zero(va_list args, const char *str, int i, int j)
{
	int	count;
	unsigned long long int	temp;
	int	temp2;
	int	precision;
	int	len_arg;

	temp = 0;
	temp2 = 0;	
	precision = check_precision(str, i, j);
	if (str[j] == 'd' || str[j] == 'i')
		temp2 = define_negative(args);
	else
		temp = define_args(args, j, str);
	count = 0;
	
	if (!((temp == 0 && temp2 == 0 ) && precision == 0))
	{
		if (check_flag_plus(i, j, str) == 1)
			count++;	
		if (check_flag_hashtag(i, j, str) == 1)
		{
			if (str[j] == 'x')
				count += 2;
			if (str[j] == 'X')
				count += 2;
		}
		if (check_flag_blank(i, j, str) == 1)
			count++;
	}
	if (str[j] == 'd' || str[j] == 'i')
	{
			temp = (unsigned long long int)temp2;
			if (temp2 < 0)
			{
				count++;
				temp = (unsigned long long int)-temp2;
			}
	}
	len_arg = ft_get_len(temp, j, str, precision);
	if (precision == -1 )
	{
		if (check_flag_plus(i, j, str) == 1)
			write(1, "+", 1);	
		if (check_flag_hashtag(i, j, str) == 1)
		{
			if (str[j] == 'x')
				write(1, "0x", 2);
			if (str[j] == 'X')
				write(1, "0X", 2);
		}
		if (check_flag_blank(i, j, str) == 1)
			write(1, " ", 1);
		if (temp2 < 0)
			write(1, "-", 1);
		count += len_arg;
		while(count < check_width_field(str, i, j))
		{
			write(1, "0", 1);
			count++;
		}
	}
	else
	{
		if (temp == 0 && precision == 0)
			len_arg = 0;
		while (len_arg < precision)
			len_arg++;
		count += len_arg;
		while(count < check_width_field(str, i, j))
		{
			write(1, " ", 1);
			count++;
		}
		if (check_flag_plus(i, j, str) == 1)
			write(1, "+", 1);	
		if (check_flag_hashtag(i, j, str) == 1)
		{
			if (str[j] == 'x')
				write(1, "0x", 2);
			if (str[j] == 'X')
				write(1, "0X", 2);
		}
		if (check_flag_blank(i, j, str) == 1)
			write(1, " ", 1);
		if (temp2 < 0)
			write(1, "-", 1);
		len_arg = ft_get_len(temp, j, str, precision);
		while (len_arg < precision)
		{
			write(1, "0", 1);
			len_arg++;
		}
	
	}
	if (!(temp == 0 && precision == 0))
		ft_print_args(str, j, temp, 0);
	return (count);
}
