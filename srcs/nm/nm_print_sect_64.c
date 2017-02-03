/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_sect_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:21:19 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 19:26:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_print_sect_64(const int uc, const uint64_t value,
			const uint8_t sect_val, const struct mach_header_64 *m_header)
{
	nm_display_addr_64(value, "0123456789abcdef");
	if (uc == MIN && sect_val != 0 && m_header != NULL)
		ft_putchar('Q');
	else
		ft_putchar('q');
	ft_putchar(' ');
}
