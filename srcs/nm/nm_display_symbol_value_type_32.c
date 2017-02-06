/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_display_symbol_value_type_32.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:19:58 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 19:15:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_display_symbol_value_type_32(const struct nlist *data,
			const t_item item, const struct mach_header *m_header,
			const t_info *info)
{
	t_symbol_info_32	sy_info;

	nm_init_symbol_info_32(&sy_info, data[item.cur].n_type, m_header, info);
	if (sy_info.stab != 0)
		return (NO_DISP);
	else if (sy_info.pext == 1 && sy_info.type == N_UNDF)
		return (nm_print_undefined_32(MIN));
	else if (sy_info.type == N_UNDF || sy_info.type == N_PBUD)
		return (nm_print_undefined_32(MAJ));
	else if (sy_info.type == N_ABS && sy_info.ext == 1)
		return (nm_print_absolute_32(MAJ, data[item.cur].n_value));
	else if (sy_info.type == N_ABS && sy_info.ext == 0)
		return (nm_print_absolute_32(MIN, data[item.cur].n_value));
	else if (sy_info.type == N_SECT && sy_info.ext == 1)
		return (nm_print_sect_32(MAJ, data[item.cur].n_value,
			data[item.cur].n_sect, &sy_info));
	else if (sy_info.type == N_SECT && sy_info.ext == 0)
		return (nm_print_sect_32(MIN, data[item.cur].n_value,
			data[item.cur].n_sect, &sy_info));
	else if (sy_info.type == N_INDR && sy_info.ext == 1)
		return (nm_print_absolute_32(MAJ, data[item.cur].n_value));
	else if (sy_info.type == N_INDR && sy_info.ext == 0)
		return (nm_print_absolute_32(MIN, data[item.cur].n_value));
	else
		return (nm_print_unknown_32());
}
