/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_macho_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 14:35:19 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 10:16:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_macho_32(const t_info *info,
			const struct mach_header *start_macho)
{
	struct load_command		*lc;
	uint32_t				i;

	if (otool_is_interval_valid((size_t)start_macho, sizeof(struct mach_header),
			info) == OTOOL_FAIL)
		return ((otool_error_handler(ERR_INVALID_FILE)));
	lc = (void *)start_macho + sizeof(struct mach_header);
	i = 0;
	while (i < cvrt_u32(start_macho->ncmds, info))
	{
		if (otool_is_interval_valid((size_t)lc, sizeof(struct load_command),
				info) == OTOOL_FAIL)
			return ((otool_error_handler(ERR_INVALID_FILE)));
		if (cvrt_u32(lc->cmd, info) == LC_SEGMENT)
		{
			if (otool_check_section_32(start_macho, (void *)lc, info)
					== OTOOL_FAIL)
				return ((otool_error_handler(ERR_INVALID_FILE)));
		}
		lc = (void *)lc + cvrt_u32(lc->cmdsize, info);
		i++;
	}
	return (OTOOL_OK);
}
