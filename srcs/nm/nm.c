/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:07:11 by cledant           #+#    #+#             */
/*   Updated: 2017/02/02 12:42:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		no_file_nm(void)
{
	int				fd;
	void			*ptr;
	struct stat		file_stat;

	if ((fd = open("a.out", O_RDONLY)) < 0)
		return (nm_error_handler(ERR_NO_A_OUT));
	if (fstat(fd, &file_stat) == -1)
		return (nm_error_handler(ERR_FSTAT));
	if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (nm_error_handler(ERR_MMAP));
	nm_start(ptr, file_stat.st_size, "a.out");
	if (munmap(ptr, file_stat.st_size) == -1)
		return (nm_error_handler(ERR_MUNMAP));
	if (close(fd) == -1)
		return (nm_error_handler(ERR_CLOSE));
	return (NM_OK);
}

static int		single_file_nm(const int i, char **argv)
{
	int				fd;
	void			*ptr;
	struct stat		file_stat;

	if (ft_strlen(argv[i]) == 0)
		return (nm_error_handler(ERR_NAME));
	if ((fd = open(argv[i], O_RDONLY)) < 0)
		return (nm_error_handler(ERR_OPEN));
	if (fstat(fd, &file_stat) == -1)
		return (nm_error_handler(ERR_FSTAT));
	if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (nm_error_handler(ERR_MMAP));
	nm_start(ptr, file_stat.st_size, argv[i]);
	if (munmap(ptr, file_stat.st_size) == -1)
		return (nm_error_handler(ERR_MUNMAP));
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
			single_file_nm(i, argv);
			i++;
		}
	}
	return (0);
}
