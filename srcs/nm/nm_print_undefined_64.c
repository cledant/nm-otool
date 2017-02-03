/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_undefined_64.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:11:38 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 19:11:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_print_undefined_64(const int uc)
{
	ft_putstr("                 ");
	if (uc == MIN)
		ft_putchar('u');
	else
		ft_putchar('U');
	ft_putchar(' ');
}
