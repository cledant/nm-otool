/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_check_symtab_64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:31:40 by cledant           #+#    #+#             */
/*   Updated: 2017/02/02 19:31:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_check_symtab_64(const struct symtab_command *symtab,
			const t_info *infoi, const struct mach_header_64 *start_macho)
{
	if (nm_is_interval_valid((size_t)symtab, sizeof(struct symtab_command),
			info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if (nm_is_interval_valid((size_t)start_macho + (size_t)(symtab->stroff),
			symtab->strsize, info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if (nm_is_interval_valid((size_t)start_macho + (size_t)(symtab->symoff),
			symtab->nsyms * sizeof(struct nlist_64), info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	return (NM_OK);
}
