/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_display_symtab_32.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:25:51 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 16:00:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline static int		display_one_symtab(const t_nm_info_32 *info_32,
							const t_info *info)
{
	struct nlist		*data;
	char				*str;
	t_item				item;

	data = info_32->symtab->symoff + (void *)(info_32->m_header);
	str = info_32->symtab->stroff + (void *)(info_32->m_header);
	item.cur = info_32->sort_tab[info_32->i];
	item.max = info_32->symtab->nsyms;
	if (nm_display_symbol_value_type_32(data, item, info_32->m_header, info)
			== DISP)
		ft_putendl(str + data[info_32->sort_tab[info_32->i]].n_un.n_strx);
	return (NM_OK);
}

int						nm_display_symtab_32(const struct mach_header
							*start_macho, const struct symtab_command *symtab,
							const t_info *info, const size_t *sort_tab)
{
	t_nm_info_32	nm_info;

	nm_info.i = 0;
	nm_info.m_header = start_macho;
	nm_info.symtab = symtab;
	nm_info.info = info;
	nm_info.sort_tab = sort_tab;
	while (nm_info.i < symtab->nsyms)
	{
		if (display_one_symtab(&nm_info, info) == NM_FAIL)
			return (nm_error_handler(ERR_INVALID_FILE));
		(nm_info.i)++;
	}
	return (NM_OK);
}
