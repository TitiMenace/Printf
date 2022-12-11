/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_casual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:54:49 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/11 02:24:33 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	fb_casual(va_list args, const char *str, int i, int j)
{
	int	count;
	int	len_arg;
	unsigned long long int	temp;
	int	temp2;
	char	*temp3;
	
	temp2 = 0;
	if (str[j] == 'd' || str[j] == 'i')
	{
		temp2 = define_negative(args);
	}
	if (str[j] == 's')
		temp3 = define_string(args);
	else
	{
		temp = define_args(args, j, str);
	}
	count = 0;
	if (check_flag_plus(i, j, str) == 1)
		count++;	
	if (check_flag_hashtag(i, j, str) == 1)
		count += 2;
	if (check_flag_blank(i, j, str) == 1)
		count++;
	if (temp2 < 0)
	{
		count++;
		temp = (unsigned long long int)-temp2;
	}
	if (temp2 >= 0)
		temp = (unsigned long long int)temp2;
	if (str[j] != 's')
		len_arg = ft_get_len(temp, j, str);
	else
		len_arg = ft_strlen(temp3);
	if (str[j] != 's')
	{	
		while (len_arg < check_precision(str, i, j))
			count++;
		count += len_arg;
		while (count < check_width_field(str, i, j))
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
			else
				write(1, "0X", 2);
		}
		if (check_flag_blank(i, j, str) == 1)
			write(1, " ", 1);
		if (temp2 < 0)
			write(1, "-", 1);
		while (len_arg < check_precision(str, i, j))
			write(1, "0", 1);
	}
	else
	{
		while (check_precision > 0 && (check_precision(str, i, j) < len_arg))
			len_arg--;
		count += len_arg;
		while(count < check_width_field(str, i, j))
		{
			write(1, " ", 1);
			count++;
		}
	}
	if (str[j] != 's')
		ft_print_args(str, j, temp, len_arg);
	else
		ft_putnstr(temp3, count);
	return (count);
}
