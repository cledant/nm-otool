/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_absolute_64.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:53:39 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 16:06:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_print_absolute_64(const int uc, const uint64_t value)
{
	nm_display_addr_64(value, "0123456789abcdef");
	if (uc == MIN)
		ft_putchar('a');
	else
		ft_putchar('A');
	ft_putchar(' ');
	return (DISP);
}
