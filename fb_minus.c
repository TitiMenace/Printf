/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:44:13 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/01 16:24:34 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fb_minus(char *buffer, int i, int j, char *str)
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
	count2 = get_len(va_list args, *j, str);
	if (str[j] != s)
	{
		while ( count2 < check_precision(str, i, j))
		{
			ft_strcat("0", buffer);
			count2++;
		}	
	}
	print_args(va_list args, str, &j);
	count += count2;
	while ( count < check_width_field(str, i, j))
	{
		ft_strcat(" ", buffer);
		count++;
	}
	return (count)	
}
