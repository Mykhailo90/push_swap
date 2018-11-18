/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 06:29:19 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 18:13:02 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_digitcounter(int n)
{
	int		dc;

	dc = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		dc++;
	}
	if (n < 0)
		dc++;
	return (dc);
}

static	int		ft_flag(int n)
{
	int flag;

	flag = 1;
	if (n < 0)
		flag = -flag;
	return (flag);
}

char			*ft_itoa(long long n)
{
	char	*str;
	int		stop;
	int		size;

	stop = 0;
	size = ft_digitcounter(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (ft_flag(n) == -1)
		str[0] = '-';
	if (n < 0)
		stop = 1;
	while (--size >= stop)
	{
		if (n >= 0)
			str[size] = n % 10 + '0';
		else
			str[size] = '0' - n % 10;
		n = n / 10;
	}
	return (str);
}
