/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:40:20 by cledant           #+#    #+#             */
/*   Updated: 2017/01/25 18:44:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static int		error_handler(const t_init_error err)
{
	if (err == ERR_ARGC)
		ft_putendl("otool : argument number invalid");
	else if (err == ERR_OPEN)
		ft_putendl("otool : error openning file");
	else if (err == ERR_FSTAT)
		ft_putendl("otool : error getting file stats");
	else if (err == ERR_MMAP)
		ft_putendl("otool : error allocating memory");
	else if (err == ERR_MUNMAP)
		ft_putendl("otool : error releasing memory");
	else if (err == ERR_CLOSE)
		ft_putendl("otool : error closing file");
	return (-1);
}

int		main(int argc, char **argv)
{
	int				fd;
	void			*ptr;
	struct stat		file_stat;

	if (argc != 2)
		return (error_handler(ERR_ARGC));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (error_handler(ERR_OPEN));
	if (fstat(fd, &file_stat) == -1)
		return (error_handler(ERR_FSTAT));
	if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (error_handler(ERR_MMAP));
	otool_start(ptr);
	if (munmap(ptr, file_stat.st_size) == -1)
		return (error_handler(ERR_MUNMAP));
	if (close(fd) == - 1)
		return (error_handler(ERR_CLOSE));
	return (0);
}
