/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_display_symtab_64.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:47:36 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 15:01:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		display_one_symtab(const t_nm_info *nm_info_64)
{

}

int				nm_display_symtab_64(const struct mach_header_64 *start_macho,
					const struct symtab_command *symtab, const t_info *info,
					const size_t *sort_tab)
{
	t_nm_info_64	nm_info;

	nm_info.i = 0;
	nm_info.m_header = start_macho;
	nm_info.symtab = symtab;
	nm_info.info = info;
	nm_info.sort_tab = sort_tab;
	while (i < symtab->nsyms)
	{
		if (display_single_symtab(&nm_info) = NM_FAIL)
			return (nm_error_handler(ERR_INVALID_FILE));
		(nm_info.i)++;
	}
	return (NM_OK);
}
