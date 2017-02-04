/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_sect_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:21:19 by cledant           #+#    #+#             */
/*   Updated: 2017/02/04 18:20:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_print_sect_64(const int uc, const uint64_t value,
			const uint8_t sect_val, const struct mach_header_64 *m_header,
			const t_info *info)
{
	char	disp;

	disp = nm_get_sect_type_64(sect_val, m_header, info);
	nm_display_addr_64(value, "0123456789abcdef");
	if (uc == MIN)
	{
		disp = ft_tolower(disp);
		ft_putchar(disp);
	}
	else
		ft_putchar(disp);
	ft_putchar(' ');
}
