/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_macho_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:15:23 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 18:22:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_macho_64(const t_info *info,
			const struct mach_header_64 *start_macho)
{
	struct load_command		*lc;
	uint32_t				i;

	ft_putendl("Mach-o 64"); //delete this
	if (otool_is_interval_valid((size_t)start_macho,
			sizeof(struct mach_header_64), info) == OTOOL_FAIL)
		return ((otool_error_handler(ERR_INVALID_FILE)));
	lc = (void *)start_macho + sizeof(struct mach_header_64);
	i = 0;
	while (i < uint32_swap_endian(start_macho->ncmds, info))
	{
		if (otool_is_interval_valid((size_t)lc, sizeof(struct load_command),
				info) == OTOOL_FAIL)
			return ((otool_error_handler(ERR_INVALID_FILE)));
		if (uint32_swap_endian(lc->cmd, info) == LC_SEGMENT_64)
		{
			if (otool_display_section_64(start_macho,
					(void *)lc, info) == OTOOL_FAIL)
				return ((otool_error_handler(ERR_INVALID_FILE)));
		}
		lc = (void *)lc + uint32_swap_endian(lc->cmdsize, info);
		i++;
	}
	return (OTOOL_OK);
}
