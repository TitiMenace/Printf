/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:59:18 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/06 03:51:48 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned int temp)
{
	unsigned int	nb;

	nb = temp;
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_args(const char *str, int j, t_ull_int temp, int count)
{
	if (str[j] == 'i' || str[j] == 'd' || str[j] == 'u')
	{
		ft_putnbr((unsigned int)temp);
		return (ft_nb_len((int)temp));
	}
	if (str[j] == 'c')
	{
		ft_putchar((char)temp);
		return (1);
	}
	if (str[j] == 'x' || str[j] == 'X' || str[j] == 'p')
		return (ft_put_hexa(str, j, temp));
	if (str[j] == 's')
	{
		if ((char *)temp == 0)
			return (0);
		return (ft_putnstr((char *)temp, count));
	}
	return (0);
}
