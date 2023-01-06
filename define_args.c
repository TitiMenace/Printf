/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:42:44 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/06 03:54:02 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	define_negative(va_list args)
{
	int	temp;

	temp = va_arg(args, int);
	return (temp);
}

t_ull_int	define_args(va_list args, int j, const char *str)
{
	t_ull_int	temp;

	if (str[j] == 'c')
	{
		temp = (t_ull_int)va_arg(args, int);
		return (temp);
	}
	if (str[j] == 'p')
	{
		temp = (t_ull_int)va_arg(args, unsigned long int);
		return (temp);
	}
	if (str[j] == 's')
	{
		temp = (t_ull_int)va_arg(args, char *);
		if (temp == (t_ull_int) NULL)
			temp = (t_ull_int)"(null)";
		return (temp);
	}
	if (str[j] == 'x' || str[j] == 'X' || str[j] == 'u')
	{
		temp = (t_ull_int)va_arg(args, unsigned int);
		return (temp);
	}
	return (0);
}
