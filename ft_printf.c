/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:05:03 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/19 04:47:59 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

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

	//setbuf(stdout, NULL);

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		init_parse(str, &i, &count);
		j = i;
		if (str[i] == '%')
		{
			j++;
			second_parse(&j, str);
			if (check_charset(str[j], "cdiupsxX%") == 1)
			{
				count += fill_buffer(args, i, j, str);
				i = j + 1;
			}
			else
				init_parse(str, &i, &count);
		}
	}
	va_end(args);
	return (count);
}
#include <stdio.h>
#include <limits.h>
/*int	main()
{
	int i;
	int j;
	i = ft_printf("%-c", 0);
	printf("\n\n");
	j = printf("%-c", 0);
	printf("\n\n");
	printf("%d", i);
	printf("\n\n");
	printf("%d", j);
}*/
