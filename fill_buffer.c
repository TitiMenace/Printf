/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:04:44 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/09 19:23:23 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fill_buffer(int *i, int *j, char *str)
{
	if (check_flag_minus(&i, &j, str) == 1)
		return (fb_minus(&i, &j, str));
	if (check_flag_zero(&i, &j, str) == 1)
		return (fb_zero(&i, &j, str));
	else
		return (fb_casual(&i, &j, str));	
}
