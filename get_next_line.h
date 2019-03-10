#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 32
# define CHECKKK 0
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h> //to delete



int						get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	int				fd;
	char			*tmp;
	char			*text;
	struct s_gnl	*next;
}				t_gnl;

#endif
