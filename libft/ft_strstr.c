/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 10:26:25 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 00:29:50 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	char	*a;
	char	*b;
	size_t	i;
	size_t	j;

	a = (char *)str;
	b = (char *)substr;
	i = 0;
	j = 0;
	if (b[i] == '\0')
		return ((char *)str);
	while (a[i] != '\0')
	{
		while (a[i + j] == b[j])
		{
			j++;
			if (b[j] == '\0')
				return (&a[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
