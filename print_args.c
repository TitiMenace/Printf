/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:42:44 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/01 18:05:57 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_args(char *str, int *j)
{
	if (str[*j] == 'd')
		return ((int)ft_putnbr(va_args(args, int)));
	if (str[*j] == 'i')
		return ((int)ft_putnbr(va_args(args, int)));
	if (str[*j] == 'c')
		return ((int)ft_putchar(va_args(args, char)));
	return (0);
}



