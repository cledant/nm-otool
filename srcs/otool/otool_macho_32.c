/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_macho_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:55:36 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 17:52:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

// A MODIF POUR GERER L ENDIANNESS

int		otool_macho_32(const t_info *info, const void *start_macho)
{
	struct mach_header		*header;
	uint32_t				ncmds;
	struct load command		*lc;
	uint32_t				i;

	if (otool_is_mem_addr_valid(info, (size_t)start_macho +
			sizeof(struct mach_header) == OTOOL_FAIL))
		return ((otool_error_handler(ERR_INVALID_FILE)));
	header = (struct mach_header *)start_macho;
	lc = (struct load_command *)start_macho + sizeof(struct mach_header);
	i = 0;
	while (i < header->ncmds)
	{
		if ((otool_is_mem_addr_valid(info, (size_t)lc) == OTOOL_FAIL) ||
				(otool_is_mem_addr_valid(info, (size_t)lc +
				sizeof(struct load_command)) == OTOOL_FAIL))
			return ((otool_error_handler(ERR_INVALID_FILE)));
		if (lc->cmd == LC_SEGMENT)
		{
			if (otool_qqch(lc, info) == OTOOL_FAIL)
				return ((otool_error_handler(ERR_INVALID_FILE)));
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	return (OTOOL_OK);
}
