/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:14:35 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:31:32 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dst;
	size_t	i;

	dst = (char *)dest;
	i = 0;
	while ((dst[i] = src[i]) != 0)
		i++;
	return (dest);
}
