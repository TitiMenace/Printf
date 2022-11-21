/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff_cas_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:54:49 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/21 04:53:44 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_buff(char *str, int *i, int *j, char *buffer)
{
	int	count;

	count = 0;
	if (check_flag_plus(&i, &j, str) == 1)
		count++;	
	if (check_flag_hashtag(&i, &j, str) == 1)
		count += 2;
	if (check_flag_blank(&i, &j, str) == 1)
		count++;
	while (ft_strlen(args) < check_precision(str, &i, &j))
	{
		ft_strcat(" ", buffer);
		count++;
	}
	count = count + ft_strlen(varg);
	while (count < check_width_field(str, &i, &j));	
	{
		ft_strcat(" ", buffer);
		count++;
	}
	if (check_flag_plus(&i, &j, str) == 1)
		ft_strcat("+", buffer);
	if (check_flag_hashtag(&i, &j, str) == 1)
	{	
		if (str[*j] == x)
			ft_strcat("0x", buffer);
		else
			ft_strcat("0x", buffer);
	{
	if (check_flag_blank(&i, &j, str) == 1)
		ft_strcat(" ", buffer);
	ft_strcat(print_arg(args), buffer);
}
