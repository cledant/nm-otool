/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:40:20 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 20:13:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		main(int argc, char **argv)
{
	int				fd;
	void			*ptr;
	struct stat		file_stat;

	if (argc != 2)
		return (otool_error_handler(ERR_ARGC));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (otool_error_handler(ERR_OPEN));
	if (fstat(fd, &file_stat) == -1)
		return (otool_error_handler(ERR_FSTAT));
	if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (otool_error_handler(ERR_MMAP));
	otool_start(ptr, file_stat.st_size);
	if (munmap(ptr, file_stat.st_size) == -1)
		return (otool_error_handler(ERR_MUNMAP));
	if (close(fd) == -1)
		return (otool_error_handler(ERR_CLOSE));
	return (0);
}
