/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:05:03 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/10 04:11:38 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	if (str[i] == '\0')
	{
		va_end(args)
		return(count)
	}	
	if (second_parse(&j, str) == 0 )
		count = count + (ft_putstr(&str[i]));
	else
		count += fill_buffer(args, &i, &j, str);
	va_end(args);
	return (count);
}
