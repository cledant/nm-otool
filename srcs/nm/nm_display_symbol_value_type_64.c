/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_display_symbol_value_64.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:16:20 by cledant           #+#    #+#             */
/*   Updated: 2017/02/04 12:09:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_display_symbol_value_type_64(const struct nlist_64 *data,
			const size_t item, const struct mach_header_64 *m_header)
{
	t_symbol_info	sy_info;

	nm_init_symbol_info(&sy_info, data[item].n_type);
	if (sy_info.stab != 0)
		return ;
	else if (sy_info.pext == 1)
		nm_print_undefined_64(MAJ);
	else if (sy_info.type == N_UNDF || sy_info.type == N_PBUD)
		nm_print_undefined_64(MIN);
	else if (sy_info.type == N_ABS && sy_info.ext == 1)
		nm_print_absolute_64(MAJ, data[item].n_value);
	else if (sy_info.type == N_ABS && sy_info.ext == 0)
		nm_print_absolute_64(MIN, data[item].n_value);
	else if (sy_info.type == N_SECT && sy_info.ext == 1)
		nm_print_sect_64(MAJ, data[item].n_value, data[item].n_sect, m_header);
	else if (sy_info.type == N_SECT && sy_info.ext == 0)
		nm_print_sect_64(MIN, data[item].n_value, data[item].n_sect, m_header);
	else if (sy_info.type == N_INDR)
		nm_display_symbol_value_type_64(data, data[item].n_value, m_header);
	else
		nm_print_unknown_64();
}
