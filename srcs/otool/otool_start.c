/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:03:23 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 16:37:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_start(const void *start_file, const off_t file_size)
{
	t_info	info;

	if (size < 0 || size < sizeof(uint32_t))
		return (otool_error_handler(ERR_INVALID_FILE));
	otool_set_info(&info, start_file, file_size);
	otool_set_endianness(&info, start_file);
	if (*(uint32_t *)start_file == FAT_MAGIC | *(uint32_t *)start_file
			== FAT_CIGAM)
		ft_putendl("Fat file type");
	else if (*(uint32_t *)start_file == MH_MAGIC | *(uint32_t *)start_file
			== MH_CIGAM)
		otool_macho_32(&info, start_file);
	else if (*(uint32_t *)start_file == MH_MAGIC_64 | *(uint32_t *)start_file
			== MH_CIGAM_64)
		ft_putendl("Mach-o 64 file type");
	else
		return (otool_error_handler(ERR_FILE_UNKNOWN));
	return (0);
}
