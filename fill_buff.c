/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:44:13 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/20 02:13:24 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_buff_if_minus()
{
	int	count;
	int	count2;

	temp1 = 0;
	if (check_flag_minus(i, j, str) == 1)
	{
		if (check_flag_plus(i, j, str) == 1)
		{
			// append '+' buffer
			count++;	
		}
		if (check_flag_hashtag(i, j, str) == 1)
		{
			if (str[j] == x)
				// append '0' et 'x' buffer
				count+2;
			else
				// append '0' et 'X' buffer
				count+2;
		{
		if (check_flag_blank(i, j, str) == 1)
		{
				// append ' ' buffer
				count++;
		}
	}
	count2 = 0;
	if (str[j] != s)
	{
		while ( < check_precision(str, i, j))
		{
			//append buffer '0'
			count2++;
		}	
	}
	// fill buff avec var avec option sur les balises string pour tronquer avec la precision.
	count += count2;
	while (temp2 + ft_strlen(printarg) < check_width_field(str, i, j))
	{
		// append ' ' buffer
		count++;
	}	
}

