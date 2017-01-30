/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_macho_fat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:18:42 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 10:15:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_macho_fat(const t_info *info,
			const struct fat_header *start_file)
{
	uint32_t			i;
	struct fat_arch		*fat;

	if (otool_is_interval_valid((size_t)start_file, sizeof(struct fat_header),
			info) == OTOOL_FAIL)
		return (otool_error_handler(ERR_INVALID_FILE));
	i = 0;
	fat = (void *)start_file + sizeof(struct fat_header);
	ft_putnbrendl(cvrt_u32(start_file->nfat_arch, info));
	while (i < cvrt_u32(start_file->nfat_arch, info))
	{
		if (otool_is_interval_valid((size_t)fat, sizeof(struct fat_arch),
				info) == OTOOL_FAIL)
			return (otool_error_handler(ERR_INVALID_FILE));
		if (otool_is_interval_valid((size_t)start_file + cvrt_u32(fat->offset,
				info), cvrt_u32(fat->size, info) ,info) == OTOOL_FAIL)
			return (otool_error_handler(ERR_INVALID_FILE));
		if (otool_start((void *)start_file + cvrt_u32(fat->offset, info),
				cvrt_u32(fat->size, info), info->arg, OTOOL_NO_FAT) != OTOOL_OK)
			return (OTOOL_FAIL);
		i++;
		fat = (void *)fat + sizeof(struct fat_arch);
	}
	return (OTOOL_OK);
}
