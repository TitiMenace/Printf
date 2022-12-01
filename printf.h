/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:01:27 by tschecro          #+#    #+#             */
/*   Updated: 2022/12/01 11:20:13 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define "printf.h"

#include <unistd.h>
#include <stdarg.h>

struct  precision {
    sign = { +, , #}
    width = {}
}

int	check_charset(char c, char *set);
int	ft_strlen(char *str);

#endif
