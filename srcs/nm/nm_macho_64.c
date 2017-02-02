/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_macho_64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:01:29 by cledant           #+#    #+#             */
/*   Updated: 2017/02/02 16:56:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_macho_64(const t_info *info,
			const struct mach_header_64 *start_macho)
{
	struct load_command		*lc;
	uint32_t				i;

	if (nm_is_interval_valid((size_t)start_macho,
			sizeof(struct mach_header_64), info) == NM_FAIL)
		return ((nm_error_handler(ERR_INVALID_FILE)));
	lc = (void *)start_macho + sizeof(struct mach_header_64);
	i = 0;
	while (i < cvrt_u32(start_macho->ncmds, info))
	{
		if (nm_is_interval_valid((size_t)lc, sizeof(struct load_command),
				info) == NM_FAIL)
			return ((nm_error_handler(ERR_INVALID_FILE)));
		if (cvrt_u32(lc->cmd, info) == LC_SYMTAB)
		{
			if (nm_check_symtab_64((void *)lc, info, start_macho)
					== NM_FAIL)
				return (NM_FAIL);
		}
		lc = (void *)lc + cvrt_u32(lc->cmdsize, info);
		i++;
	}
	return (NM_OK);
}
