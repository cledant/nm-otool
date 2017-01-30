/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_fat_arch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:35:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 15:31:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_fat_arch(const t_info *info,
			const struct fat_header *start_file)
{
	t_fat_info		fat_info;

	otool_init_fat_info(&fat_info);
	if (otool_check_fat_arch_x86_64(info, start_file, &fat_info) != OTOOL_OK)
		return (OTOOL_FAIL);
	if (fat_info.cpu == CPU_TYPE_ANY)
	{
		if (otool_check_fat_arch_x86(info, start_file, &fat_info) != OTOOL_OK)
			return (OTOOL_FAIL);
	}
	if (fat_info.cpu == CPU_TYPE_ANY)
		otool_fat_display_all(info, start_file);
	else
		otool_fat_display_one(start_file, &fat_info, info);
	return (OTOOL_OK);
}
