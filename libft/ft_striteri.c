/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:06:20 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:01:40 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if ((s != NULL))
		i = 0;
	else
		return ;
	if (f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
