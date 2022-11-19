/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 05:15:53 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/16 20:27:22 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *to, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!to && !len)
		return (NULL);
	i = 0;
	if (!find[0])
		return ((char *)to);
	while (to[i] && i < len)
	{
		j = 0;
		while (to[i + j] == find[j] && i + j < len)
		{
			j++;
			if (!find[j])
				return ((char *)&to[i]);
		}
		i++;
	}
	return (NULL);
}
