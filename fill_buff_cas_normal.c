/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff_cas_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:54:49 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/20 03:09:09 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_buff_()
{
	int	count;

	count = 0;
	if (check_flag_plus(i, j, str) == 1)
		count++;	
	if (check_flag_hashtag(i, j, str) == 1)
		count += 2;
	if (check_flag_blank(i, j, str) == 1)
		count++;
	count = count + ft_strlen(varg);
	if (check_precison)
		while (count < check_width_filed(str, i, j))
		{
			//append ' ' buffer
			count++;
		}
	else
		// check les priorite entre precision et field
	
	if (check_flag_plus(i, j, str) == 1)
		// append '+' buffer
	if (check_flag_hashtag(i, j, str) == 1)
	{	
		if (str[j] == x)
			// append '0' et 'x' buffer
		else
			// append '0' et 'X' buffer
	{
	if (check_flag_blank(i, j, str) == 1)
		// append ' ' buffer
	// fill buff avec var option sur les balises string pour tronquer
}
