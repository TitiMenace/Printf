/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:25:21 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/06 03:53:25 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putadd(t_ull_int temp)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (temp >= 16)
		count += ft_putadd(temp / 16);
	count += write(1, &base[temp % 16], 1);
	return (count);
}

int	ft_putaddress(t_ull_int temp)
{
	write(1, "0x", 2);
	return (ft_putadd(temp) + 2);
}

int	ft_putnbr_hexa(unsigned int nb)
{
	char	*hexa;
	int		count;

	count = 0;
	hexa = "0123456789abcdef";
	if (nb >= 16)
		count += ft_putnbr_hexa(nb / 16);
	count += write(1, &hexa[nb % 16], 1);
	return (count);
}

int	ft_putnbr_hexa_maj(unsigned int nb)
{
	char	*hexa;
	int		count;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_putnbr_hexa_maj(nb / 16);
	count += write(1, &hexa[nb % 16], 1);
	return (count);
}

int	ft_put_hexa(const char *str, int j, t_ull_int temp)
{
	t_ull_int	temp2;

	temp2 = (t_ull_int)"(nil)";
	if (str[j] == 'x')
		return (ft_putnbr_hexa(temp));
	if (str[j] == 'X')
		return (ft_putnbr_hexa_maj((unsigned int)temp));
	if (str[j] == 'p')
	{
		if (temp == temp2)
			return (ft_putnstr("(nil)", 5));
		return (ft_putaddress(temp));
	}
	return (0);
}
