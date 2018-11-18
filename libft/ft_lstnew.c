/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:00:54 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/20 19:01:51 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	if (!(newlink = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size > 0)
	{
		if (!(newlink->content = (void *)malloc(content_size)))
		{
			free(newlink);
			return (NULL);
		}
		ft_memcpy(newlink->content, content, content_size);
		newlink->content_size = content_size;
	}
	else
	{
		newlink->content = NULL;
		newlink->content_size = 0;
	}
	newlink->next = NULL;
	return (newlink);
}
