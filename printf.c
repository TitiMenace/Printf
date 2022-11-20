/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:05:03 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/19 22:05:05 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str,...)
{
	va_list	args;
	int	i;
	int	count;
	
	va_start(args, str);
	i = 0;
	while (str[i] && str[i] != '%')
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	if (str[i] == '%')
	{
		i++;
		count += print_args(i, args, str);
	}
	return (count);
}

int	main()
{
	ft_printf("ouais gros");
}
