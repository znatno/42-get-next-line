/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:54:34 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/10 15:23:03 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*create_list(const int fd)
{
		t_gnl	*new;

		if (new = (t_gnl*)malloc(sizeof(*new)))
		{
			new->fd = fd;
			new->buff = ft_strnew(0);
			new->tmp = NULL;
			new->next = NULL;
			return (new);
		}
		return (NULL);
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
	static t_gnl	*saved;
	char			buff[BUF_SIZE + 1];
	//char			**str;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!*saved)
	saved = create_list(fd);
	ret = read(fd, buff, BUF_SIZE);
	buff[ret] = '\0';
	saved->buff = buff;
	printf("%s\n", saved->buff);
	free(saved);
	return (0);
}
