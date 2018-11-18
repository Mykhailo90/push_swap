/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:34:34 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 18:37:44 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		dlen;

	d = dst;
	s = src;
	i = size;
	while (*d != '\0' && i-- != 0)
		d++;
	dlen = d - dst;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(s));
	while (*s != 0)
	{
		if (i > 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
