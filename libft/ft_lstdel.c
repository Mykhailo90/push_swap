/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:25:57 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/20 22:25:14 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*start;
	t_list	*next;

	start = *alst;
	while (start)
	{
		del(start->content, start->content_size);
		next = start->next;
		free(start);
		start = next;
	}
	(*alst) = NULL;
}
