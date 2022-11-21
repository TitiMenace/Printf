/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 07:06:57 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/21 00:28:10 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//faire une fonction en changeant les trucs en parametre

int	check_flag_0(int i, int j, char *str)
{
	int	temp;

	temp = i;
	while (temp < j)
	{
		if (str[temp] == '0')
			return (1);
		temp++;
	}
	return (0);
}

int	check_flag_minus(int i, int j, char *str)
{
	int	temp;

	temp = i;
	while (temp < j)
	{
		if (str[temp] == '-')
			return (1);
		temp++;
	}
	return (0);
}

int	check_flag_plus(int i, int j, char *str)
{
	int	temp;

	temp = i;
	while (temp < j)
	{
		if (str[temp] == '+')
			return (1);
		temp++;
	}
	return (0);
}

int	check_flag_blank(int i, int j, char *str)
{
	int	temp;

	temp = i;
	while (temp < j)
	{
		if (str[temp] == ' ')
			return (1);
		temp++;
	}
	return (0);
}

int	check_flag_hashtag(char flag, int i, int j, char *str)
{
	int	temp;

	temp = i;	
	while (temp < j)
	{
		if (str[temp] == '#')
			return (1);
		temp++;
	}
	return (0);
}
