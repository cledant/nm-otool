/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_set_endianness.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:13:05 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 20:18:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	otool_set_endianness(t_info *info, const uint32_t *start_file)
{
	if (*start_file == MH_CIGAM || *start_file == MH_CIGAM_64 || 
			*start_file == FAT_CIGAM)
		info->endianness = LITTLE;
}
