/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:26:05 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/12 05:22:20 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str, int precision)
{
	int	i;
	
	i = 0;
	if (precision >= 0)
	{
		while (i < precision && str[i])
			i++;
	}
	else
	{
		while (str[i])
			i++;
	}
	return (i);
}

int	ft_hexa_len(unsigned long long int temp)
{
	char	*base;
	int	count;

	base = "0123456789abcdef";
	count = 0;
	if (temp >= 16)
		count += ft_hexa_len(temp / 16);
	count++;
	return (count);

}

int	ft_nb_len(int n)
{
	int count;
	int nb;

	count = 0;
	nb = n;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_get_len(unsigned long long int temp, int j, const char *str, int precision)
{

	int	result;

	if (str[j] == 'i' || str[j] == 'd' || str[j] == 'u')
		return (ft_nb_len((int)temp));
	if (str[j] == 's')
	{
		if ((char *)temp == 0)
			return (0);
		result = ft_strlen((char *)temp, precision);
		return (result);
	}
	if (str[j] == 'c')
		return (1);
	if (str[j] == 'p')
		return (ft_hexa_len(temp) + 2);
	if (str[j] == 'x' || str[j] == 'X')
		return (ft_hexa_len(temp));
	return (0);
}
