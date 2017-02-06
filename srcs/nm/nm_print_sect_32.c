/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_sect_32.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:00:11 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 16:08:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_print_sect_32(const int uc, const uint32_t value,
			const uint8_t sect_val, const t_symbol_info_32 *si)
{
	char	disp;

	disp = nm_get_sect_type_32(sect_val, si->m_header, si->info);
	nm_display_addr_32(value, "0123456789abcdef");
	if (uc == MIN)
	{
		disp = ft_tolower(disp);
		ft_putchar(disp);
	}
	else
		ft_putchar(disp);
	ft_putchar(' ');
	return (DISP);
}
