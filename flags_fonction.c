/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 07:06:57 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/19 04:32:44 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag_zero(int i, int j, const char *str)
{
	int	temp;

	temp = i;
	while (temp < j && str[temp] != '.' && ( str[temp] <= '0' || str[temp] > '9'))
	{
		if (str[temp] == '0')
			return (1);
		temp++;
	}
	return (0);
}

int	check_flag_minus(int i, int j, const char *str)
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

int	check_flag_plus(int i, int j, const char *str)
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

int	check_flag_blank(int i, int j, const char *str)
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

int	check_flag_hashtag(int i, int j, const char *str)
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
