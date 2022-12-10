/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:04:44 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/10 00:28:56 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fill_buffer(va_list args, int *i, int *j, char *str)
{
	if (check_flag_minus(&i, &j, str) == 1)
		return (fb_minus(args, &i, &j, str));
	if (check_flag_zero(&i, &j, str) == 1)
		return (fb_zero(args, &i, &j, str));
	else
		return (fb_casual(args, &i, &j, str));	
}
