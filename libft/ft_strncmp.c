/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:54:51 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 12:59:08 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;
	size_t			i;

	i = 0;
	first = (unsigned char *)s1;
	second = (unsigned	char *)s2;
	while (n > i && first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
			return ((unsigned int)(first[i] - second[i]));
		i++;
	}
	if ((first[i] == 0 || second[i] == 0) && (i != n))
		return ((unsigned int)(first[i] - second[i]));
	return (0);
}
