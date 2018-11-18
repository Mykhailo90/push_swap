/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:25:57 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 13:25:53 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*start;

	if (!lst)
		return (NULL);
	new_list = f(lst);
	start = new_list;
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = f(lst);
		new_list = new_list->next;
	}
	return (start);
}
