/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_macho_32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:57:42 by cledant           #+#    #+#             */
/*   Updated: 2017/02/08 11:08:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_macho_32(const t_info *info,
			const struct mach_header *start_macho, const int argc)
{
	struct load_command		*lc;
	uint32_t				i;

	if (nm_is_interval_valid((size_t)start_macho,
			sizeof(struct mach_header), info) == NM_FAIL)
		return ((nm_error_handler(ERR_INVALID_FILE)));
	lc = (void *)start_macho + sizeof(struct mach_header);
	i = 0;
	if (argc > 2)
		nm_print_macho_name(info->arg);
	while (i < cvrt_u32(start_macho->ncmds, info))
	{
		if (nm_is_interval_valid((size_t)lc, sizeof(struct load_command),
				info) == NM_FAIL)
			return ((nm_error_handler(ERR_INVALID_FILE)));
		if (cvrt_u32(lc->cmd, info) == LC_SYMTAB)
		{
			if (nm_check_symtab_32((void *)lc, info, start_macho)
					== NM_FAIL)
				return (NM_FAIL);
		}
		lc = (void *)lc + cvrt_u32(lc->cmdsize, info);
		i++;
	}
	return (NM_OK);
}
