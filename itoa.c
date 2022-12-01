/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:30:58 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/01 10:31:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	len_n(long n)
{
	long	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(long n)
{
	char	*out;
	long	len;
	long	nb;

	nb = (long)n;
	len = len_n(n);
	out = malloc(sizeof(char) * len + 1);
	if (!out)
		return (NULL);
	if (n < 0)
	{
		nb *= -1;
		out[0] = '-';
	}
	out[len] = 0;
	if (nb == 0)
		out[0] = '0';
	while (nb > 0)
	{
		len--;
		out[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (out);
}
