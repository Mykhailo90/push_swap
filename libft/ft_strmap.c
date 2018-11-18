/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:36:53 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:35:41 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*c;
	char	s2;
	int		i;

	i = 0;
	if (s && f)
	{
		c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!c)
			return (NULL);
		while (*s)
		{
			s2 = f(*s++);
			if (s2)
				c[i++] = s2;
		}
		c[i++] = '\0';
		return (c);
	}
	return (NULL);
}
