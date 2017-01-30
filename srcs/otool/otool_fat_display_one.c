/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_fat_display_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:17:04 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 15:27:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_fat_display_one(const struct fat_header *start_file,
			const t_fat_info *fat_info, const t_info *info)
{
	if (otool_is_interval_valid((size_t)start_file + fat_info->offset,
			fat_info->size, info) == OTOOL_FAIL)
		return (otool_error_handler(ERR_INVALID_FILE));
	otool_start((void *)start_file + fat_info->offset, fat_info->size,
		info->arg, OTOOL_NO_FAT);
	return (OTOOL_OK);
}
