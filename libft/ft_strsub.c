/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:45:12 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:47:00 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	if (s1 != NULL)
	{
		i = 0;
		ptr = ft_strnew(len);
		if (ptr != NULL)
		{
			while (i < len)
			{
				ptr[i] = s1[i + start];
				++i;
			}
			ptr[i] = '\0';
		}
		return (ptr);
	}
	return (NULL);
}
