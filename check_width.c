/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:48:11 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/20 00:30:56 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	small_atoi(char *str, int i)
{
	int	k;

	k = 0;
	while (str[i] >= '1' && str[i] <= '9')
	{
		k = k * 10 + (str[i] - 48);
		i++;
	}
	return (k);
}

int	check_precision(char *str, int i, int j)
{
	int temp;

	temp = i;
	while (temp < j)
	{
		if(str[temp] == '.')
			return (small_atoi(str, temp, j));
		temp++;
	}
	return (0);
}

int	check_width_field(char *str, int i, int j)
{
	int temp;

	temp = i;
	while (temp < j && str[temp] != . && )
	{
		if (str[temp] >= '1' && str[i] <= '9)
		{
			temp += 1;
			return (small_atoi(str, temp, j));
		}
	}
	return (0);
}
