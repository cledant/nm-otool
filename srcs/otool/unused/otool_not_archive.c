/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:03:23 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 16:03:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_start(const void *start_file, const off_t file_size,
			const char *arg, const int fat)
{
	t_info	info;

	if (file_size < 0 || file_size < (long long int)sizeof(uint32_t) ||
			file_size < (long long int)(sizeof(char) * 8))
		return (otool_error_handler(ERR_INVALID_FILE));
	otool_init_info(&info, start_file, file_size, arg);
	otool_set_endianness(&info, start_file);
	if ((info.name = ft_strdup(info.arg)) == NULL)
		return (otool_error_handler(ERR_MEM));
	if ((*(uint32_t *)start_file == FAT_MAGIC || *(uint32_t *)start_file
			== FAT_CIGAM) && fat == OTOOL_CHECK_FAT)
		otool_macho_fat(&info, (struct fat_header *)start_file);
	else if (*(uint32_t *)start_file == MH_MAGIC || *(uint32_t *)start_file
			== MH_CIGAM)
		otool_macho_32(&info, (struct mach_header *)start_file);
	else if (*(uint32_t *)start_file == MH_MAGIC_64 || *(uint32_t *)start_file
			== MH_CIGAM_64)
		otool_macho_64(&info, (struct mach_header_64 *)start_file);
	else
		return (otool_error_handler(ERR_UNKNOWN));
	if (info.name != NULL)
		free(info.name);
	return (OTOOL_OK);
}
