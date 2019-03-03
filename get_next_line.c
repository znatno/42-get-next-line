/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:54:34 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/03 19:44:05 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*create_list(const int fd)
{
		t_gnl	*new;

		if (!(new = (t_gnl*)malloc(sizeof(*new))))
			return (NULL);
		new = (t_gnl*)malloc(sizeof(*new));
		new->fd = fd;
		new->buff = ft_strnew(0);
		new->tmp = NULL;
		new->next = NULL;
		return (new);
}

/*
** int				fd_count()
** {
** // провірка на мультидескрипторність
** }
*/

/*
** int				check_list()
** {
** // провірка чи віддаємо
** }
*/

int						get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	//char			*buff;

	if (fd < 0 || !line)
		return (-1);
	if (!(list= (t_gnl*)malloc(sizeof(*list))))
		return (-1);
	list = create_list(fd);
	printf("x08\n");
	return (0);
}
