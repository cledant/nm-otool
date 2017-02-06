/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_check_symtab_32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:00:40 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 11:23:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_check_symtab_32(const struct symtab_command *symtab,
			const t_info *info, const struct mach_header *start_macho)
{
	size_t		*sort_tab;

	if (nm_is_interval_valid((size_t)symtab, sizeof(struct symtab_command),
			info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if (nm_is_interval_valid((size_t)start_macho + (size_t)(symtab->stroff),
			symtab->strsize, info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if (nm_is_interval_valid((size_t)start_macho + (size_t)(symtab->symoff),
			symtab->nsyms * sizeof(struct nlist), info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if (nm_is_string_tab_valid((void *)start_macho + symtab->stroff,
			symtab->strsize) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if ((sort_tab = nm_new_size_t_tab(symtab->nsyms)) == NULL)
		return (nm_error_handler(ERR_MEM));
	if (nm_sort_symtab(sort_tab, symtab->nsyms, (void *)start_macho +
			symtab->stroff, (void *)start_macho + symtab->symoff) == NM_FAIL)
	{
		free(sort_tab);
		return (nm_error_handler(ERR_SORT));
	}
	nm_display_symtab_32(start_macho, symtab, info, sort_tab);
	free(sort_tab);
	return (NM_OK);
}
