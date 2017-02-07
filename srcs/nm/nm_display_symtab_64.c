/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_display_symtab_64.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:47:36 by cledant           #+#    #+#             */
/*   Updated: 2017/02/07 15:18:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline static int		display_one_symtab(const t_nm_info_64 *info_64,
							const t_info *info)
{
	struct nlist_64		*data;
	char				*str;
	t_item				item;

	data = info_64->symtab->symoff + (void *)(info_64->m_header);
	str = info_64->symtab->stroff + (void *)(info_64->m_header);
	item.cur = info_64->sort_tab[info_64->i];
	item.max = info_64->symtab->nsyms;
	if (nm_display_symbol_value_type_64(data, item, info_64->m_header, info)
			== DISP)
		ft_putendl(str + data[info_64->sort_tab[info_64->i]].n_un.n_strx);
	return (NM_OK);
}

int						nm_display_symtab_64(const struct mach_header_64
							*start_macho, const struct symtab_command *symtab,
							const t_info *info, const size_t *sort_tab)
{
	t_nm_info_64	nm_info;

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
