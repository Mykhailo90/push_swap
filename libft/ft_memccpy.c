/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:53:38 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 18:09:05 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dest;
	char	*source;
	size_t	i;

	dest = (char*)dst;
	source = (char*)src;
	i = 0;
	while (n)
	{
		dest[i] = source[i];
		if (source[i] == c)
			return (&dest[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
