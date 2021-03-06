/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:16:05 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:50:07 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		n;

	if (s1 && s2)
	{
		if (!(ret = (char*)malloc(sizeof(char) * ((ft_strlen(s1)
		+ ft_strlen(s2)) + 1))))
			return (NULL);
		n = 0;
		while (s1[n] != '\0')
		{
			ret[n] = s1[n];
			n++;
		}
		while (*s2)
			ret[n++] = *s2++;
		ret[n] = '\0';
		return (ret);
	}
	return (NULL);
}
