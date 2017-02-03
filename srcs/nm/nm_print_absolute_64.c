/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_absolute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:10:16 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 19:14:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_print_absolute_64(const int uc, const uint64_t value)
{
	nm_display_addr_64(value, "0123456789abcdef");
	if (uc == MIN)
		ft_putchar('a');
	else
		ft_putchar('A');
	ft_putchar(' ');
}
