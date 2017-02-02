/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_is_mem_addr_valid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:11:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 17:11:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

inline int	otool_is_mem_addr_valid(const t_info *info, const size_t addr)
{
	if (addr > info->end || addr < info->start)
		return (OTOOL_FAIL);
	return (OTOOL_OK);
}
