/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:42:44 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/10 04:06:22 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	define_negative(va_list args)
{
	int	temp;

	temp = va_args(args, int);
	return (temp);
}

unsigned long long int	define_args(va_list args, int *j, char *str)
{
	unsigned long long int	temp;

	if (str[*j] == 'c')
	{
		temp = (unsigned long long int)va_args(args, int);
		return (temp);
	}
	if (str[*j] == 'p')
	{
		temp = va_args(args, unsigned long int);
		return (temp);
	}
	if (str[*j] == 's')
	{
		temp = (unsigned long long int)va_args(args, char *);
		return (temp);
	}
	if (str[*j] == 'x' || str[*j] == 'X' || str[*j] == 'u')
	{
		temp = va_args(args, unsigned int);
		return (temp);	
	}
}


