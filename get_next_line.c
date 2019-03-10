/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:54:34 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/10 19:53:12 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_new_list(const int fd)
{
		t_gnl	*new;

		if (!(new = (t_gnl*)malloc(sizeof(*new))))
				return (NULL);
		new->fd = fd;
		new->tmp = ft_strnew(0);
		new->text = NULL;
		new->next = NULL;
		return (new);
}

static t_gnl	*ft_fd_check(t_gnl *saved, int fd)
{
	t_gnl	*clist;
	t_gnl	*new;
	t_gnl	*add;

	new = NULL;
	clist = saved;
	while (clist)
	{
		if (clist->fd == fd)
			return (clist);
		if (!(clist->next))
		{
			new = ft_new_list(fd);
			add = clist;
			while (add->next)
				add = add->next;
			add->next = new;
			return (new);
		}
		clist = clist->next;
	}
	return (NULL);
}

static int		ft_clear(t_gnl *clr)
{
	t_gnl *t;

	while (clr)
	{
		if (clr->text)
			free(clr->text);
		t = clr->next;
		free(clr);
		clr = t;
	}
	return (END_OF_INPUT);
}

static int		ft_rtrn_check(char *str, char **line, t_gnl *saved)
{
	char	*fin;

	if (!str)
		return (ft_clear(saved));
	fin = ft_strchr(str, '\n');
	if (fin != NULL)
	{
		*fin = '\0';
		*line = ft_strdup(str);
		ft_strncpy(str, &fin[1], ft_strlen(&fin[1]) + 1);
		return (GOING_MORE);
	}
	else if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (GOING_MORE);
	}
	return (ft_clear(saved));
}


int				get_next_line(const int fd, char **line)
{
	static t_gnl	*saved;
	t_gnl			*now;
	char			buff[BUF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || BUF_SIZE <= 0)
		return (ERROR);
	if (!saved)
		saved = ft_new_list(fd);
	now = ft_fd_check(saved, fd);
	while (!(ft_strchr(now->tmp, '\n')))
	{
		ret = read(fd, buff, BUF_SIZE);
		if (ret == -1)
			return (ERROR);
		if (ret == 0)
			return (ft_rtrn_check(now->tmp, line, saved));
		buff[ret] = '\0';
		now->text = ft_strjoin(now->tmp, buff);
		free(now->tmp);
		now->tmp = now->text;
	}
	return (ft_rtrn_check(now->tmp, line, saved));
}
