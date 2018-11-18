/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:05:19 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 14:09:59 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	short	i;

	d = (char*)dst;
	s = (char*)src;
	if (s > d)
		ft_memcpy(d, s, len);
	else
	{
		i = (short)len - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dst);
}
