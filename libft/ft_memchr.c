/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:51:49 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/09 05:51:53 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptdr;
	unsigned char	ptr;

	ptdr = (unsigned char *)s;
	ptr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptdr[i] == ptr)
			return (ptdr + i);
		i++;
	}
	return (NULL);
}
