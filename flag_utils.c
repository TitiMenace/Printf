/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:30:06 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/05 19:34:24 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_count_flags(const char *str, int j, int i, ull_int temp)
{
	int	count;

	count = 0;
	if (check_flag_plus(i, j, str) == 1)
		count++;	
	if (check_flag_hashtag(i, j, str) == 1 && (unsigned int)temp != 0)
		count += 2;
	if (check_flag_blank(i, j, str) == 1)
		count++;
	return (count);
}

void ft_print_flags(const char *str, int j, int i, ull_int temp)
{
	if (check_flag_plus(i, j, str) == 1)
		write(1, "+", 1);
	if (check_flag_hashtag(i, j, str) == 1 && (unsigned int)temp != 0)
	{
		if (str[j] == 'x')
			write(1, "0x", 2);
		if (str[j] == 'X')
			write(1, "0X", 2);
	}
	if (check_flag_blank(i, j, str) == 1)
		write(1, " ", 1);
}
