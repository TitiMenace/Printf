/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 05:08:28 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/17 18:49:43 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	i;

	if (fd < 0)
		return ;
	if (fd)
	{
		i = 0;
		if (nb < 0)
		{
			i = nb * -1;
			ft_putchar_fd('-', fd);
		}
		else
			i = nb;
		if (i <= 9)
			ft_putchar_fd(i + '0', fd);
		else
		{
			ft_putnbr_fd(i / 10, fd);
			ft_putnbr_fd(i % 10, fd);
		}
	}
}
