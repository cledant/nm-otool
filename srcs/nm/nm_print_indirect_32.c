/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_indirect_32.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:11:19 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 19:11:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_print_indirect_32(const int uc, const uint32_t value)
{
	nm_display_addr_32(value, "0123456789abcdef");
	if (uc == MIN)
		ft_putchar('i');
	else
		ft_putchar('I');
	ft_putchar(' ');
	return (DISP);
}
