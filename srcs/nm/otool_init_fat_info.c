/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_init_fat_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:52:41 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 15:31:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	otool_init_fat_info(t_fat_info *fat_info)
{
	fat_info->cpu = CPU_TYPE_ANY;
	fat_info->size = 0;
	fat_info->offset = 0;
}
