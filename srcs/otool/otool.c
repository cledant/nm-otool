/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:40:20 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 10:47:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static int		close_routine(const t_error err, const int fd)
{
	otool_error_handler(err);
	if (close(fd) == -1)
		return (otool_error_handler(ERR_CLOSE));
	return (OTOOL_FAIL);
}

static int		single_file_otool(const int i, char **argv)
{
	int				fd;
	void			*ptr;
	struct stat		file_stat;

	if (ft_strlen(argv[i]) == 0)
		return (otool_error_handler(ERR_NAME));
	if ((fd = open(argv[i], O_RDONLY)) < 0)
		return (otool_error_handler(ERR_OPEN));
	if (fstat(fd, &file_stat) == -1)
		return (close_routine(ERR_FSTAT, fd));
	if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (close_routine(ERR_MMAP, fd));
	otool_start(ptr, file_stat.st_size, argv[i]);
	if (munmap(ptr, file_stat.st_size) == -1)
		return (close_routine(ERR_MUNMAP, fd));
	if (close(fd) == -1)
		return (otool_error_handler(ERR_CLOSE));
	return (OTOOL_OK);
}

int				main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		single_file_otool(i, argv);
		i++;
	}
	return (0);
}
