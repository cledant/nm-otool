/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_set_endianness.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:51:05 by cledant           #+#    #+#             */
/*   Updated: 2017/02/02 12:51:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void		nm_set_endianness(t_info *info, const uint32_t *start_file)
{
	if (*start_file == MH_CIGAM || *start_file == MH_CIGAM_64 ||
			*start_file == FAT_CIGAM)
		info->endian = LITTLE;
}
