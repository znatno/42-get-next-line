/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:27:29 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/11 14:28:06 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 32
# define GOING_MORE 1
# define END_OF_INPUT 0
# define ERROR -1
# include <fcntl.h>
# include "libft/libft.h"

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	int				fd;
	char			*tmp;
	char			*text;
	struct s_gnl	*next;
}				t_gnl;

#endif
