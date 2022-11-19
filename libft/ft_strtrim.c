/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 05:20:47 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/16 18:47:57 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_char(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	j = ft_strlen((char *)s1) - 1;
	i = 0;
	count = 0;
	while (is_charset(s1[i], set) && s1[i])
		i++;
	while (is_charset(s1[j], set) && j > i)
		j--;
	while (i <= j)
	{
		i++;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	str = malloc(sizeof(char) * (count_char(s1, set) + 1));
	if (!str)
		return (NULL);
	while (is_charset(s1[i], set) && s1[i])
		i++;
	while (j < count_char(s1, set))
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}
