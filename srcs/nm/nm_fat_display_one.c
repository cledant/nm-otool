/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat_display_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:27:05 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 22:28:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_fat_display_one(const struct fat_header *start_file,
			const t_fat_info *fat_info, const t_info *info)
{
	if (nm_is_interval_valid((size_t)start_file + fat_info->offset,
			fat_info->size, info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	nm_start((void *)start_file + fat_info->offset, fat_info->size,
		info->arg);
	return (NM_OK);
}
