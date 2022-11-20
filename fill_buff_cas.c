/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff_cas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:39:41 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/20 02:53:15 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_buff_cas_0()
{
	int	count;

	count = 0;
	if (check_flag_0(i, j, str) == 1)
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
		count = count + ft_strlen(vaarg);
		while (count < check_width_field(str, i, j))
		{
			//append 0
			count++;
		}
		// fill buff avec var options balises avec tronquage

	}
}
