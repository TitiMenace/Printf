/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:48:11 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/05 16:02:41 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	small_atoi(const char *str, int i)
{
	int	k;

	k = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + (str[i] - 48);
		i++;
	}
	return (k);
}

int	check_precision(const char *str, int i, int j)
{
	int	count;

	count = -1;
	while (i < j)
	{
		if (str[i] == '.')
		{
			i++;
			count = small_atoi(str, i);
			return (count);
		}
		i++;
	}
	return (count);
}

int	check_width_field(const char *str, int i, int j)
{
	while (i < j && str[i] != '.')
	{
		if (str[i] >= '1' && str[i] <= '9')
			return (small_atoi(str, i));
		i++;
	}
	return (-1);
}
