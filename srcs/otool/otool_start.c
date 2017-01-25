/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:03:23 by cledant           #+#    #+#             */
/*   Updated: 2017/01/25 18:32:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	otool_start(const void *ptr)
{
	if (*(unsigned int *)ptr == FAT_MAGIC)
		ft_putendl("Fat file type");
	if (*(unsigned int *)ptr == MH_MAGIC_64)
		ft_putendl("Mach-o 32 file type");
	if (*(unsigned int *)ptr == MH_MAGIC)
		ft_putendl("Mach-o 64 file type");
}
