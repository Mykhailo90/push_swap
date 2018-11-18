/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:12:12 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 17:12:50 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fill(unsigned int work, int m, int minus, char *ret)
{
	while (work >= 10)
	{
		ret[m-- + minus] = work % 10 + '0';
		work /= 10;
	}
	ret[m-- + minus] = work % 10 + '0';
	if (minus == 1)
		ret[m + minus] = '-';
}
