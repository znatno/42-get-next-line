/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:54:34 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/10 18:02:43 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*create_list(const int fd)
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
	t_gnl			*now;
	char			buff[BUF_SIZE + 1];
	int				ret;


	// if (/* умова що вже нема що віддавати*/)
	// {
	// 	/* очищення пам'яті */
	// 	return (0);
	// }

	if (fd < 0 || !line || BUF_SIZE <= 0)
		return (-1);
	if (!saved)
		saved = create_list(fd);
	// провірка фд
	now = saved;
	while (!(ft_strchr(now->tmp, '\n')))
	{
		ret = read(fd, buff, BUF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return CHECKKK;
		buff[ret] = '\0';
		now->text = ft_strjoin(now->tmp, buff);
		free(now->tmp);
		now->tmp = now->text;
		printf("%s\n", now->tmp);
	}
	return CHECKKK;
}
