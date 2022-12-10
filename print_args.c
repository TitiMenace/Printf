/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:59:18 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/10 05:01:39 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	ft_putnbr_hexa(unsigned int nb)
{
	char	*hexa;
	int	count;

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
	int	count;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_putnbr_hexa_maj(nb / 16);
	count += write(1, &hexa[nb % 16], 1);
	return (count);
}

int	ft_putaddress(unsigned long long int temp)
{
	char	*base;
	int	count;

	base = "0123456789abcdef";
	count = 0;
	if (temp >= 16)
		count += ft_hexa_len(temp / 16);
	count += write(1, &base[temp % 16], 1);
	return (count);

}

int	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i <= n)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_args(char *str, int *j, unsigned long long int temp, int count)
{
	if (str[*j] == 'i' || str[*j] == 'd' || str[*j] == 'u')
	{
		ft_putnbr((unsigned int)temp);
		return (ft_nb_len((int)temp));
	}
	if (str[*j] == 'c')
	{
		ft_putchar((char)temp);
		return (1);
	}
	if (str[*j] == 'x')
		return (ft_putnbr_hexa((unsigned int)temp));
	if (str[*j] == 'X')
		return (ft_putnbr_hexa_maj((unsigned int)temp));
	if (str[*j] == 'p')
		return (ft_putaddress(temp));
	if (str[*j] == 's')
		return ft_putnstr((char *)temp, count);
	return (0);
}
