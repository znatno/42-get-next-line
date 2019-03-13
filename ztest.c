/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:26:31 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/13 13:27:22 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		main(int ac, char *av[])
{
	int	fd[ac];
	char *temp;
	int	i;
	int	ret;

	i = -1;
	--ac;
	++av;
	if (ac > 0)
	{
		while (++i < ac)
		{
			fd[i] = open(*(av++), O_RDONLY);
			if ((ret = get_next_line(fd[i], &temp)) > 0)
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
		printf("|Successed read 1 line from each file.|\n");
		system("leaks test");
		while (--i)
			close(fd[i]);
	}
}
