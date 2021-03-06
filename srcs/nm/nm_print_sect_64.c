/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_sect_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:21:19 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 16:08:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_print_sect_64(const int uc, const uint64_t value,
			const uint8_t sect_val, const t_symbol_info_64 *si)
{
	char	disp;

	disp = nm_get_sect_type_64(sect_val, si->m_header, si->info);
	nm_display_addr_64(value, "0123456789abcdef");
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
