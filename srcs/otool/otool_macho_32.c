/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_macho_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:55:36 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 20:40:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

// A MODIF POUR GERER L ENDIANNESS

int		otool_macho_32(const t_info *info,
			const struct mach_header *start_macho)
{
	struct load_command		*lc;
	uint32_t				i;

	if (otool_is_interval_valid((size_t)start_macho, sizeof(struct mach_header),
			info) == OTOOL_FAIL)
		return ((otool_error_handler(ERR_INVALID_FILE)));
	lc = (struct load_command *)start_macho + sizeof(struct mach_header);
	i = 0;
	while (i < start_macho->ncmds)
	{
		if (otool_is_interval_valid((size_t)lc, sizeof(struct load_command),
				info) == OTOOL_FAIL)
			return ((otool_error_handler(ERR_INVALID_FILE)));
		if (lc->cmd == LC_SEGMENT)
		{
			if (otool_display_section_32(start_macho,
					(struct segment_command *)lc, info) == OTOOL_FAIL)
				return ((otool_error_handler(ERR_INVALID_FILE)));
		}
		lc = lc + lc->cmdsize; //ici
		i++;
	}
	return (OTOOL_OK);
}
