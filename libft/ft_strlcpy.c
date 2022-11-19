/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 05:09:59 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/16 21:42:29 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen((char *)src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		if (i <= (size_t)ft_strlen((char *)src))
				dest[i] = src[i];
		else
				dest[i] = 0;
		i++;
	}
	dest[i] = 0;
	return (ft_strlen((char *)src));
}
