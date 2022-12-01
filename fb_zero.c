/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:39:41 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/01 14:14:17 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fb_zero(char *str, int *i, int *j, char *buffer)
{
	int	count;
	
	count = 0;
	if (check_flag_plus(&i, &j, str) == 1)
	{
		ft_strcat("+", buffer);
		count++;	
	}
	if (check_flag_hashtag(&i, &j, str) == 1)
	{
		if (str[*j] == x)
			ft_strcat("0x", buffer);
		count+2;
		else
			ft_strcat("0X", buffer);
		count+2;
	}
	if (check_flag_blank(&i, &j, str) == 1)
	{
		ft_strcat(" ", buffer);
		count++;
	}
	while (ft_strlen(args) < check_precision(str, &i, &j))
	{
		ft_strcat("0", buffer);
		count++;
	}

		count = count + ft_strlen(vaarg);
		ft_strcat(ft_print_arg(args), buffer);
	}
}
