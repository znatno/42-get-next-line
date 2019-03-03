/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohun <ibohun@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:55:12 by ibohun            #+#    #+#             */
/*   Updated: 2019/03/03 19:03:58 by ibohun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	printf("x\n");
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	printf("x10\n");
	while (get_next_line(fd, &line) == 1)
	{
		printf("x18\n");
		ft_putendl(line);
		printf("x17\n");
		free(line);
		printf("x16\n");
	}
	printf("x19\n");
	if (argc == 2)
		close(fd);
}
