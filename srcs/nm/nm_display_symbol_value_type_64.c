/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_display_symbol_value_64.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:16:20 by cledant           #+#    #+#             */
/*   Updated: 2017/02/07 15:36:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int	next_tests(const t_symbol_info_64 *sy_info,
				const struct nlist_64 *data)
{
	if (sy_info->type == N_INDR && sy_info->ext == 0)
		return (nm_print_indirect_64(MIN, data[item.cur].n_value));
	else
		return (nm_print_unknown_64());
}

int			nm_display_symbol_value_type_64(const struct nlist_64 *data,
				const t_item item, const struct mach_header_64 *m_header,
				const t_info *info)
{
	t_symbol_info_64	sy_info;

	nm_init_symbol_info_64(&sy_info, data[item.cur].n_type, m_header, info);
	if (sy_info.stab != 0)
		return (NO_DISP);
	else if (sy_info.type == N_UNDF && sy_info.ext == 1 &&
			data[item.cur].n_value != 0)
		return (nm_print_common_64(data[item.cur].n_value));
	else if (sy_info.pext == 1 && sy_info.type == N_UNDF)
		return (nm_print_undefined_64(MIN));
	else if (sy_info.type == N_UNDF || sy_info.type == N_PBUD)
		return (nm_print_undefined_64(MAJ));
	else if (sy_info.type == N_ABS && sy_info.ext == 1)
		return (nm_print_absolute_64(MAJ, data[item.cur].n_value));
	else if (sy_info.type == N_ABS && sy_info.ext == 0)
		return (nm_print_absolute_64(MIN, data[item.cur].n_value));
	else if (sy_info.type == N_SECT && sy_info.ext == 1)
		return (nm_print_sect_64(MAJ, data[item.cur].n_value,
			data[item.cur].n_sect, &sy_info));
	else if (sy_info.type == N_SECT && sy_info.ext == 0)
		return (nm_print_sect_64(MIN, data[item.cur].n_value,
			data[item.cur].n_sect, &sy_info));
	else if (sy_info.type == N_INDR && sy_info.ext == 1)
		return (nm_print_indirect_64(MAJ, data[item.cur].n_value));
	return (next_tests(&sy_info, data));
}
