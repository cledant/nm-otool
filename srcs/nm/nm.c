/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:07:11 by cledant           #+#    #+#             */
/*   Updated: 2017/02/08 10:55:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		close_routine(const t_error err, const int fd)
{
	nm_error_handler(err);
	if (close(fd) == -1)
		return (nm_error_handler(ERR_CLOSE));
	return (NM_FAIL);
}

static int		no_file_nm(void)
{
	int				fd;
	void			*ptr;
	struct stat		file_stat;

	if ((fd = open("a.out", O_RDONLY)) < 0)
		return (nm_error_handler(ERR_NO_A_OUT));
	if (fstat(fd, &file_stat) == -1)
		return (close_routine(ERR_FSTAT, fd));
	if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (close_routine(ERR_MMAP, fd));
	nm_start(ptr, file_stat.st_size, "a.out", 2);
	if (munmap(ptr, file_stat.st_size) == -1)
		return (nm_error_handler(ERR_MUNMAP));
	if (close(fd) == -1)
		return (nm_error_handler(ERR_CLOSE));
	return (NM_OK);
}

static int		single_file_nm(const int i, char **argv, const int argc)
{
	int				fd;
	void			*ptr;
	struct stat		file_stat;

	if (ft_strlen(argv[i]) == 0)
		return (nm_error_handler(ERR_NAME));
	if ((fd = open(argv[i], O_RDONLY)) < 0)
		return (nm_error_handler(ERR_OPEN));
	if (fstat(fd, &file_stat) == -1)
		return (close_routine(ERR_FSTAT, fd));
	if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (close_routine(ERR_MMAP, fd));
	nm_start(ptr, file_stat.st_size, argv[i], argc);
	if (munmap(ptr, file_stat.st_size) == -1)
		return (close_routine(ERR_MUNMAP, fd));
	if (close(fd) == -1)
		return (nm_error_handler(ERR_CLOSE));
	return (NM_OK);
}

int				main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		no_file_nm();
	else
	{
		while (i < argc)
		{
			single_file_nm(i, argv, argc);
			i++;
		}
	}
	return (0);
}
