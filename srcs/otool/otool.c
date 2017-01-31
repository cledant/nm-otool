/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:40:20 by cledant           #+#    #+#             */
/*   Updated: 2017/01/31 15:10:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

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
		return (otool_error_handler(ERR_FSTAT));
	if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (otool_error_handler(ERR_MMAP));
	otool_start(ptr, file_stat.st_size, argv[i]);
	if (munmap(ptr, file_stat.st_size) == -1)
		return (otool_error_handler(ERR_MUNMAP));
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
