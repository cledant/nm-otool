/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_check_fat_arch_x86.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:15:59 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 22:25:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_check_fat_arch_x86(const t_info *info,
			const struct fat_header *start_file, t_fat_info *fat_info)
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
		if (cvrt_u32(fat->cputype, info) == CPU_TYPE_X86)
		{
			fat_info->cpu = cvrt_u32(fat->cputype, info);
			fat_info->size = cvrt_u32(fat->size, info);
			fat_info->offset = cvrt_u32(fat->offset, info);
			break ;
		}
		i++;
		fat = (void *)fat + sizeof(struct fat_arch);
	}
	return (NM_OK);
}
