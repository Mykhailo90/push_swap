/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 15:40:20 by msarapii          #+#    #+#             */
/*   Updated: 2018/10/14 15:40:25 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int					check_line(char *line)
{
	size_t	n;

	n = 0;
	while (line[n] != '\0')
		if (line[n++] == '\n')
			return (1);
	return (0);
}

int					ft_get_line(t_line *ptr)
{
	char	*tmp;
	char	*buf;
	int		end;

	if (ptr->sline == NULL)
		ptr->sline = ft_strnew(0);
	end = 1;
	while (end != 0 && !check_line(ptr->sline))
	{
		tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		end = read(ptr->fd, tmp, BUFF_SIZE);
		if ((end == 0 && ft_strlen(ptr->sline) == 0) || end == -1)
			free(tmp);
		if (end == 0 && ft_strlen(ptr->sline) == 0)
			return (0);
		if (end == -1)
			return (-1);
		tmp[end] = '\0';
		buf = ft_strdup(ptr->sline);
		free(ptr->sline);
		ptr->sline = ft_strjoin(buf, tmp);
		free(tmp);
		free(buf);
	}
	return (1);
}

t_line			**make_list(void)
{
	t_line		**res;

	res = (t_line**)malloc(sizeof(t_line*));
	*res = NULL;
	return (res);
}

char				*add_line(t_line *ptr)
{
	char			*res;
	char			*new;
	size_t			n;

	n = 0;
	while (ptr->sline[n] != '\n' && ptr->sline[n] != '\0')
		n++;
	res = (char*)malloc(sizeof(char) * (n + 1));
	n = 0;
	while (ptr->sline[n] != '\n' && ptr->sline[n] != '\0')
	{
		res[n] = ptr->sline[n];
		n++;
	}
	res[n] = '\0';
	if (ptr->sline[n] == '\n')
		n++;
	new = ft_strsub(ptr->sline, n, ft_strlen(ptr->sline));
	ft_strdel(&ptr->sline);
	ptr->sline = new;
	if (ft_strlen(ptr->sline) == 0)
		ft_strdel(&ptr->sline);
	return (res);
}

int					get_next_line(const int fd, char **line)
{
	static t_line	**fds;
	t_line			*ptr;
	int				res;

	if (fd < 0 || !line)
		return (-1);
	if (!fds)
		fds = make_list();
	ptr = *fds;
	if (ptr != NULL)
		while (ptr != NULL && ptr->fd != fd)
			ptr = ptr->next;
	if (ptr == NULL)
	{
		ptr = (t_line*)malloc(sizeof(t_line));
		ptr->fd = fd;
		if (!(ptr->sline = ft_strnew(0)))
			return (-1);
		ptr->next = *fds;
		*fds = ptr;
	}
	res = ft_get_line(ptr);
	*line = add_line(ptr);
	return (res);
}
