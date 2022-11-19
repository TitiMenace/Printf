/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 05:09:31 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/15 02:21:40 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptdr;

	ptr = (unsigned char *)s1;
	ptdr = (unsigned char *)s2;
	i = 0;
	if (n == 0 || (!ptr[0] && !ptdr[0]))
		return (0);
	while (i < n && (ptr[i] || ptdr[i]))
	{
		if (ptr[i] != ptdr[i])
			return ((int)(ptr[i] - ptdr[i]));
		i++;
	}
	return (0);
}
