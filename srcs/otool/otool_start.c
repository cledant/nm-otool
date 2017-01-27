/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:03:23 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 09:46:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_start(const void *start_file, const off_t file_size)
{
	t_info	info;

	if (file_size < 0 || file_size < (long long int)sizeof(uint32_t))
		return (otool_error_handler(ERR_INVALID_FILE));
	otool_init_info(&info, start_file, file_size);
	otool_set_endianness(&info, start_file);
	if (info.endianness == LITTLE)
		ft_putendl("LITTLE ENDIAN");
	else
		ft_putendl("BIG ENDIAN");
	if (*(uint32_t *)start_file == FAT_MAGIC || *(uint32_t *)start_file
			== FAT_CIGAM)
		ft_putendl("Fat file type");
	else if (*(uint32_t *)start_file == MH_MAGIC || *(uint32_t *)start_file
			== MH_CIGAM)
		otool_macho_32(&info, (struct mach_header *)start_file);
	else if (*(uint32_t *)start_file == MH_MAGIC_64 || *(uint32_t *)start_file
			== MH_CIGAM_64)
		otool_macho_64(&info, (struct mach_header_64 *)start_file);
	else
		return (otool_error_handler(ERR_UNKNOWN));
	return (0);
}
