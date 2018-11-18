/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:11:14 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 00:11:55 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_newlink(t_list *list, void *content)
{
	t_list	*linkparam;

	if (!(linkparam = malloc(sizeof(t_list))))
		return (NULL);
	if (linkparam)
	{
		linkparam->content = content;
		linkparam->next = list;
	}
	return (linkparam);
}
