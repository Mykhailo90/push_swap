/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:10:56 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/20 09:53:53 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_words(char const *str, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**res;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if ((res = (char**)malloc(sizeof(char*) * (ft_words(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		if (i == 0 || (s[i] != c && s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			res[j] = ft_strsub(s, (unsigned int)start, (size_t)i - start + 1);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
