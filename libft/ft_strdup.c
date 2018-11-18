/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:24:18 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:41:59 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen((char *)s1) + 1;
	if (!(dest = (char *)ft_memalloc(len)))
		return (NULL);
	ft_strcpy((char *)dest, (char *)s1);
	return ((char *)dest);
}
