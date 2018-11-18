/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:24:41 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:58:43 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	char			s2;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s && f)
	{
		c = (char*)malloc(ft_strlen(s) + 1);
		if (!c)
			return (NULL);
		while (s[i] != '\0')
		{
			s2 = s[i];
			if (f(i, s2))
				c[j++] = f(i, s[i]);
			i++;
		}
		c[j] = '\0';
		return (c);
	}
	return (NULL);
}
