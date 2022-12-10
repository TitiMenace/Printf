/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:26:05 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/10 05:46:36 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
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

	count = 0;
	while (n != 0)
	{
		n / 10;
		count++;
	}
	return (count);
}

int	ft_get_len( unsigned long long int temp, int j, char *str)
{
	if (str[j] == 'i' || str[j] == 'd' || str[j] == 'u')
		return (ft_nb_len((int)temp));
	if (str[j] == 's')
		return (ft_strlen((char *)temp));
	if (str[j] == 'c')
		return (1);
	if (str[j] == 'p')
		return (ft_hexa_len(temp) + 2)
	if (str[j] == 'x' || str[j] == 'X')
		return (ft_hexa_len(temp);
}
