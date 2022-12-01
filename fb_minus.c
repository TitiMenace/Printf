/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:44:13 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/01 14:14:48 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fb_minus(char *buffer, int i, int j, char *str)
{
	int	count;
	int	count2;

	temp1 = 0;
	if (check_flag_plus(i, j, str) == 1)
	{
		ft_strcat("+", buffer);
		count++;	
	}
	if (check_flag_hashtag(i, j, str) == 1)
	{
		if (str[j] == x)
			ft_strcat("0x", buffer);
		count+2;
		else
			ft_strcat("0X", buffer);
		count+2;
	}
	if (check_flag_blank(i, j, str) == 1)
	{
		ft_strcat(" ", buffer);
		count++;
	}
	count2 = 0;
	if (str[j] != s)
	{
		while ( < check_precision(str, i, j))
		{
			ft_strcat("0", buffer);
			count2++;
		}	
	}
	ft_strcat(ft_print_arg(...), buffer);
	count += count2;
	while (temp2 + ft_strlen(printarg) < check_width_field(str, i, j))
	{
		ft_strcat(" ", buffer);
		count++;
	}	
}

