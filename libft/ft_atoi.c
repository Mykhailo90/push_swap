/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:59:53 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 01:28:12 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_space(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n' || \
				c == '\v' || c == '\f' || c == '\r'));
}

long long				ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	res;

	sign = 1;
	i = 0;
	res = 0;
	while (ft_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (res > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return ((long long)(sign * res));
}
