/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:26:05 by tschecro          #+#    #+#             */
/*   Updated: 2023/01/05 16:01:15 by tschecro         ###   ########.fr       */
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
	int	count;

	count = 0;
	if (temp >= 16)
		count += ft_hexa_len(temp / 16);
	count++;
	return (count);
}

int	ft_nb_u_len(unsigned int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}	

int	ft_nb_len(int n)
{
	int	count;
	int	nb;

	count = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_get_len(unsigned long long int temp, int j, const char *str, int precision)
{
	unsigned long long int	temp2;

	temp2 = (unsigned long long int)"(nil)";
	if (str[j] == 'i' || str[j] == 'd')
		return (ft_nb_len((int)temp));
	if (str[j] == 'u')
		return (ft_nb_u_len((unsigned int) temp));
	if (str[j] == 's')
	{
		if ((char *)temp == 0)
			return (0);
		return (ft_strlen((char *)temp, precision));
	}
	if (str[j] == 'c')
		return (1);
	if (str[j] == 'p')
	{
		if (temp == temp2)
			return (5);
		return (ft_hexa_len(temp) + 2);
	}
	if (str[j] == 'x' || str[j] == 'X')
		return (ft_hexa_len(temp));
	return (0);
}
