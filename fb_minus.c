/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:44:13 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/01 17:56:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fb_minus(int *i, int *j, char *str)
{
	int	count;
	int	count2;

	count = 0;
	if (check_flag_plus(&i, &j, str) == 1)
	{
		write(1, "+", 1);
		count++;	
	}
	if (check_flag_hashtag(&i, &j, str) == 1)
	{
		if (str[*j] == x)
			write(1, "0x", 2);
		count += 2;
		else
			write(1, "0X", 2);
		count += 2;
	}
	if (check_flag_blank(&i, &j, str) == 1)
	{
		write(1, " ", 1);
		count++;
	}
	count2 = get_len(va_list args, &j, str);
	if (str[*j] != 's')
	{
		while ( count2 < check_precision(str, &i, &j))
		{
			write(1, "0", 1);
			count2++;
		}	
	}
	print_args(va_list args, str, &j);
	count += count2;
	while (count < check_width_field(str, &i, &j))
	{
		write(1, " ", 1);
		count++;
	}
	return (count)	
}
