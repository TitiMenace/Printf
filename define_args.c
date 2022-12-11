/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:42:44 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/11 10:48:03 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	define_negative(va_list args)
{
	int	temp;

	temp = va_arg(args, int);
	return (temp);
}

unsigned long long int	define_args(va_list args, int j, const char *str)
{
	unsigned long long int	temp;

	if (str[j] == 'c')
	{
		temp = (unsigned long long int)va_arg(args, int);
		return (temp);
	}
	if (str[j] == 'p')
	{
		temp = (unsigned long long int)va_arg(args, unsigned long int);
		return (temp);
	}
	if (str[j] == 's')
	{
		temp = (unsigned long long int)va_arg(args, char *);
		return (temp);
	}
	if (str[j] == 'x' || str[j] == 'X' || str[j] == 'u')
	{
		temp = (unsigned long long int)va_arg(args, unsigned int);
		return (temp);	
	}
	return (0);
}


