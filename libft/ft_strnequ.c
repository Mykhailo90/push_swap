/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:39:39 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 00:15:35 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 && s2)
	{
		if (ft_strncmp(s1, s2, n) == 0)
			return (1);
	}
	return (0);
}
