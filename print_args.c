/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:42:44 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/21 01:23:24 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_args(int i, char *str, int j)
{
	if (str[i] == 'd')
		return ((int)ft_putnbr_fd(v_args(args, int), 1));
	if (str[i] == 'i')
		return ((int)ft_putnbfr_fd(v_args(args, int), 1));
	if (str[i] == 'c')
		return ((int)ft_putchar_fd(v_args(args, int), 1));
	if (str[i] == 's')
	{	
		if (check_precision(str, i, j))
			return ((int)ft_putstr_fd(v_args(args, int)));
		else
	}
}



