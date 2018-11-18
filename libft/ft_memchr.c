/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:51:52 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 18:08:23 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*ps == (unsigned char)c)
				return ((void *)ps);
			ps++;
			n--;
		}
	}
	return (NULL);
}
