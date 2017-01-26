/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_is_interval_valid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:22:42 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 19:26:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

inline int	otool_is_interval_valid(const size_t addr, const size_t size,
				const t_info *info)
{
	if (addr > info->end || addr < info->start)
		return (OTOOL_FAIL);
	if ((addr + size) > info->end || (addr + size) < info->start)
		return (OTOOL_FAIL);
	return (OTOOL_OK);
}
