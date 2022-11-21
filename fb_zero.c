/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff_cas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:39:41 by tschecro          #+#    #+#             */
/*   Updated: 2022/11/21 05:02:40 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_buff_cas_0(char *str, int *i, int *j, char *buffer)
{
	int	count;
// regler le cas avec la precision et les 0 qui revient a annuler le faire comme si il n'existe pas donc revenir au cas normal...
	count = 0;
	if (check_flag_0(&i, &j, str) == 1)
	{
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
		{
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
