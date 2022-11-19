/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:52:16 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/09 05:52:19 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptdr;
	unsigned char	*ptr;
	size_t			i;

	ptdr = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptdr[i] != ptr[i])
			return (ptdr[i] - ptr[i]);
		i++;
	}
	return (0);
}
