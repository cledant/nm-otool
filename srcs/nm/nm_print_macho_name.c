/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_macho_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:05:18 by cledant           #+#    #+#             */
/*   Updated: 2017/02/08 11:05:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		nm_print_macho_name(const char *arg)
{
	ft_putchar('\n');
	ft_putstr(arg);
	ft_putendl(":");
}
