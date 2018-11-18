/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:55:32 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:43:43 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dest;

	dest = dst;
	while (len > 0 && *src != '\0')
	{
		*dest++ = *src++;
		--len;
	}
	ft_bzero(dest, len);
	return (dst);
}
