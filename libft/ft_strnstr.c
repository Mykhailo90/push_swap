/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:28:09 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 13:36:31 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;
	char	*a;
	char	*b;

	a = (char *)str;
	b = (char *)substr;
	i = 0;
	j = 0;
	if (b[j] == '\0' || (!b))
		return ((char *)str);
	while (i < len && a[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && a[i + j] == b[j])
		{
			j++;
			if (b[j] == '\0')
				return (&a[i]);
		}
		i++;
	}
	return (NULL);
}
