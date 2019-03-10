#include <stdio.h>
#include <fcntl.>
#include "includes/gnl_header.h"

int		main(int ac, char *av[])
{
	--ac;
	++av;
	if (ac > 0)
	{
		int	fd[ac];
		char *temp;
		int	i = -1;
		int	ret;
		while (++i < ac)
		{
			fd[i] = open(*(av++), O_RDONLY);
			if ((ret = gnl(fd, &temp)) > 0)
				printf("Readed: %s | ret: %d\n", temp, ret);
			else
			{
				free(temp);
				temp = NULL;
				while (i)
					close(fd[i--]);
				printf("|GNL Error| ret value %d\n", ret);
				exit(1);
			}
			free(temp);
			temp = NULL;
		}
		printf("|Successed read 1 line from each file.|\n", );
		system("leaks test");
		while (--i)
			close(fd[i]);
	}
}
