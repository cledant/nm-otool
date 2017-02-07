/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_common_32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:10:58 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 19:15:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_print_common_32(const uint32_t value)
{
	nm_display_addr_32(value, "0123456789abcdef");
	ft_putchar('C');
	ft_putchar(' ');
	return (DISP);
}
