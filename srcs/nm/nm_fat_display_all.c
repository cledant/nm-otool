/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat_display_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:18:14 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 22:20:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_fat_display_all(const t_info *info,
			const struct fat_header *start_file)
{
	uint32_t			i;
	struct fat_arch		*fat;

	if (nm_is_interval_valid((size_t)start_file, sizeof(struct fat_header),
			info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	i = 0;
	fat = (void *)start_file + sizeof(struct fat_header);
	while (i < cvrt_u32(start_file->nfat_arch, info))
	{
		if (nm_is_interval_valid((size_t)fat, sizeof(struct fat_arch),
				info) == NM_FAIL)
			return (nm_error_handler(ERR_INVALID_FILE));
		if (nm_is_interval_valid((size_t)start_file + cvrt_u32(fat->offset,
				info), cvrt_u32(fat->size, info), info) == NM_FAIL)
			return (nm_error_handler(ERR_INVALID_FILE));
		if (nm_start((void *)start_file + cvrt_u32(fat->offset, info),
				cvrt_u32(fat->size, info), info->arg) != NM_OK)
			return (NM_FAIL);
		i++;
		fat = (void *)fat + sizeof(struct fat_arch);
	}
	return (NM_OK);
}
