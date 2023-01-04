/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:44:13 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/04 19:16:17 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fb_minus(va_list args, int i, int j, const char *str)
{
	int	count;
	int	len_arg;
	unsigned long long int	temp;
	int	temp2;
	int	pre_count;
	int	precision;

	len_arg  = 0;
	temp = 0;
	precision = check_precision(str, i, j);
	if (str[j] == 'd' || str[j] == 'i')
		temp2 = define_negative(args);
	else
		temp = define_args(args, j, str);
	if ((void *)temp == 0 && str[j] == 'p')
	{
		write(1, "(nil)", 5);
		return (5);
	}

	count = 0;
	if (str[j] == 'd' || str[j] == 'i')
		temp = (unsigned long long int)temp2;
	if (temp2 < 0)
	{
		write(1, "-", 1);
		count++;
		temp = (unsigned long long int)-temp2;
	}
	else
	{
		if (check_flag_plus(i, j, str) == 1)
		{
			write(1, "+", 1);
			count++;	
		}
		if (check_flag_hashtag(i, j, str) == 1)
		{
			if (str[j] == 'x')
				write(1, "0x", 2);
			count += 2;
			if (str[j] == 'X')
				write(1, "0X", 2);
			count += 2;
		}
		if (check_flag_blank(i, j, str) == 1)
		{
			write(1, " ", 1);
			count++;
		}
	}
	
	if (!(temp == 0  && precision == 0))
		len_arg = ft_get_len(temp, j, str, precision);
	pre_count = len_arg;
	if (str[j] != 's')
	{
		while (pre_count < check_precision(str, i, j))
		{
			write(1, "0", 1);
			pre_count++;
		}	
	}
	else
	{
		while (precision >= 0 && precision < len_arg)
			len_arg--;
	}
	
	count += pre_count;
	if  (!(temp == 0 && precision == 0))
		ft_print_args(str, j, temp, len_arg);
	while (count < check_width_field(str, i, j))
	{
		write(1, " ", 1);
		count++;
	}
	return (count);	
}
