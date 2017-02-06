/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_absolute_32.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:53:11 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 12:53:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_print_absolute_32(const int uc, const uint32_t value)
{
	nm_display_addr_32(value, "0123456789abcdef");
	if (uc == MIN)
		ft_putchar('a');
	else
		ft_putchar('A');
	ft_putchar(' ');
}
