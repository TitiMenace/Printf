/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:44:13 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/09 22:02:43 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	fb_minus(va_list args, int *i, int *j, char *str)
{
	int	count;
	int	count2;
	unsigned long long int	temp;
	int	temp2;

	if (str[*j] == 'd' || str[*j] == 'i')
		temp2 = define_negative(args, &j, str);
	else
		temp = define_args(args, &j, str);
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
	if (str[*j] == 'd' || str[*j] == 'i')
	{
			if (temp2 < 0)
			{
				write(1, "-", 1);
				count++;
				temp2 = -temp2;
			}
			temp = (unsigned long long int)temp2;
	}
	count2 = get_len(&j, str);
	if (str[*j] != 's')
	{
		while ( count2 < check_precision(str, &i, &j))
		{
			write(1, "0", 1);
			count2++;
		}	
	}
	print_args(str, &j);
	count += count2;
	while (count < check_width_field(str, &i, &j))
	{
		write(1, " ", 1);
		count++;
	}
	return (count)	
}
