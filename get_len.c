/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:26:05 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/09 21:58:21 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nb_len(int n)
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


int	get_len( unsigned long long int temp, int *j, char *str)
{
	if (str[*j] == 'i' || str[*j] == 'd' || str[*j] == 'u')
		return (nb_len((int)temp));
	if (str[*j] == 's')
		return (strlen((char *)temp));
	if (str[*j] == 'c')
		return (1);
	if (str[*j] == 'p')
	{

	}
	if (str[*j] == 'x' || str[j] == 'X')
	{
		
	}

}
