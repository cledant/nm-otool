/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:45:32 by cledant           #+#    #+#             */
/*   Updated: 2017/02/04 22:57:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		unknown_case(t_info *info)
{
	if (info->name != NULL)
		free(info->name);
	return (nm_error_handler(ERR_UNKNOWN));
}

int				nm_start(const void *start_file, const off_t file_size,
					const char *arg)
{
	t_info	info;

	if (file_size < 0 || file_size < (long long int)sizeof(uint32_t) ||
			file_size < (long long int)(sizeof(char) * 8))
		return (nm_error_handler(ERR_INVALID_FILE));
	nm_init_info(&info, start_file, file_size, arg);
	nm_set_endianness(&info, start_file);
	if ((info.name = ft_strdup(info.arg)) == NULL)
		return (nm_error_handler(ERR_MEM));
	if ((*(uint32_t *)start_file == FAT_MAGIC || *(uint32_t *)start_file
			== FAT_CIGAM))
		nm_fat_arch(&info, (struct fat_header *)start_file);
	else if (ft_strncmp(start_file, ARMAG, 8) == 0)
		nm_archive(&info, (void *)start_file + 8);
	else if (*(uint32_t *)start_file == MH_MAGIC || *(uint32_t *)start_file
			== MH_CIGAM)
		nm_macho_32(&info, (struct mach_header *)start_file);
	else if (*(uint32_t *)start_file == MH_MAGIC_64 || *(uint32_t *)start_file
			== MH_CIGAM_64)
		nm_macho_64(&info, (struct mach_header_64 *)start_file);
	else
		return (unknown_case(&info));
	if (info.name != NULL)
		free(info.name);
	return (NM_OK);
}
