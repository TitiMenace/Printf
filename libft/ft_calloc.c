/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 05:18:22 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/17 18:56:54 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;

	if (size && nmemb >= SIZE_MAX / size)
		return (NULL);
	out = malloc (size * nmemb);
	if (!out)
		return (NULL);
	ft_bzero(out, nmemb * size);
	return (out);
}
