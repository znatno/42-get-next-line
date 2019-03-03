/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:54:34 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/03 19:05:40 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	create_list(const int fd)
{
// створення порожнього листа
		t_gnl	*new;

		//if (!(new = (t_gnl*)malloc(sizeof(*new))))
		//	return (0);
		new = (t_gnl*)malloc(sizeof(*new));
		new->fd = fd;
		new->buff = NULL;
		new->tmp = NULL;
		new->next = NULL;
		printf("x01\n");
		return (*new);
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

	printf("x00\n");
	if (fd < 0 || !line)
		return (-1);
	printf("x07\n");
	*list = create_list(fd);
	printf("x08\n");
	return (0);
}
