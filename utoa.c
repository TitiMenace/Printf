/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:31:39 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/01 10:31:48 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	len_n(unsigned int n)
{
	long	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char			*out;
	long			len;
	long			nb;

	nb = (long)n;
	len = len_n(n);
	out = malloc(sizeof(char) * len + 1);
	if (!out)
		return (NULL);
	out[0] = '0';
	while (nb > 0)
	{
		len--;
		out[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (out);
}
