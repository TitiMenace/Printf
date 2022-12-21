/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_casual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:54:49 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/19 04:25:24 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fb_casual(va_list args, const char *str, int i, int j)
{
	int	count;
	int	len_arg;
	unsigned long long int	temp;
	int	temp2;
	int	pre_count;
	int	precision;
	unsigned long long int	temp3;

	temp3 = (unsigned long long int)"(null)";
	precision = check_precision(str, i, j);	
	temp  = 0;
	temp2 = 0;
	len_arg = 0;
	if (str[j] == 'd' || str[j] == 'i')
		temp2 = define_negative(args);
	else
		temp = define_args(args, j, str);
	//if (temp == temp3 && (precision >= 0 && precision < 6))
		//return (0);
	//if ((void *)temp == 0 && str[j] == 'p')
	//	temp = (unsigned long long int)"(nil)";
	count = 0;
	if (check_flag_plus(i, j, str) == 1)
		count++;	
	if (check_flag_hashtag(i, j, str) == 1 && (unsigned int)temp != 0)
		count += 2;
	if (check_flag_blank(i, j, str) == 1)
		count++;
	if (temp2 < 0)
	{
		count++;
		temp = (unsigned long long int)-temp2;
	}
	if (temp2 > 0)
		temp = (unsigned long long int)temp2;
	
	if (!(temp == 0 && precision == 0))
		len_arg = ft_get_len(temp, j, str, precision);
	if (str[j] != 's')
	{	
		count += len_arg;

		pre_count = len_arg;
		while (pre_count < precision && precision >= 0)
		{
			pre_count++;
			count++;
		}
		while (count < check_width_field(str, i, j))
		{
			write(1, " ", 1);
			count++;
		}
		if (check_flag_plus(i, j, str) == 1)
			write(1, "+", 1);
		if (check_flag_hashtag(i, j, str) == 1 && (unsigned int)temp != 0)
		{	
			if (str[j] == 'x')
				write(1, "0x", 2);
			else
				write(1, "0X", 2);
		}
		if (check_flag_blank(i, j, str) == 1 && temp >= 0)
			write(1, " ", 1);
		if (temp2 < 0)
			write(1, "-", 1);
		pre_count = len_arg;
		while (pre_count < precision && precision >= 0)
		{
			write(1, "0", 1);
			pre_count++;
		}
	}
	else
	{
		count += len_arg;
		while(check_width_field(str, i, j) >= 0 && count < check_width_field(str, i, j))
		{
			write(1, " ", 1);
			count++;
		}
	}
	if (!(temp == 0 && precision == 0))
		ft_print_args(str, j, temp, len_arg);
	return (count);
}
