/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:05:03 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/09 19:18:18 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_putstr(const char *str)
{
	
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	check_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_parse(const char *str, int *i, int *count)
{
	while (str[*i] && str[*i] != '%')
	{
		write(1, &str[*i], 1);
		(*i)++;
		(*count)++;
	}
}

int	second_parse(int *j, const char *str)
{
	while (str[*j] && (check_charset(str[*j], "cdiupsxX%") == 0))
		(*j)++;
	if (check_charset(str[*j], "cdiupsxX%") == 1)
		return (1);
	return (0);
}	
int	ft_printf(const char *str,...)
{
	va_list args;
	int	i;
	int	j;
	int	count;

	va_start(args, str);
	i = 0;
	count = 0;
	init_parse(str, &i, &count); //protection si chaine nulle
	j = i;
	if (str[i] == '%')
	{
		if (second_parse(&j, str) == 0 )
		{
			count = count + (ft_putstr(&str[i]));
			va_end(args);
			return (count); 
		}
		else
			va_end(args);
			return (count + fill_buffer(&i, &j, str));
	}
	else
	{
		va_end(args)
		return (count);
	}
	va_end(args);
	return (count);
}
