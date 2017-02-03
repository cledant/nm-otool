/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_macho_32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:46:55 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 22:04:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_macho_32(const t_info *info,
			const struct mach_header_64 *start_macho)
{
	if (info != NULL && start_macho != NULL)
		ft_putendl("Mach-O 32");
/*	struct load_command		*lc;
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
	}*/
	return (NM_OK);
}
