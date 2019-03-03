/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:54:34 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/03 16:56:20 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	create_list(const char **line)
{

}

int				fd_count()
{

}

int				check_list()
{

}

int				get_next_line(const int fd, const char **line)
{
	static t_gnl new;

	if (fd < 0 || !line)
		return (-1);
	new = create_list(&line);


	return (check_list(fd, line, new))
}
