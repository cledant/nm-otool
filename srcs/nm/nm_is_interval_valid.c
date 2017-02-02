/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_is_interval_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:06:18 by cledant           #+#    #+#             */
/*   Updated: 2017/02/02 13:06:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline int	nm_is_interval_valid(const size_t addr, const size_t size,
				const t_info *info)
{
	if (addr > info->end || addr < info->start)
		return (NM_FAIL);
	if ((addr + size) > info->end || (addr + size) < info->start)
		return (NM_FAIL);
	return (NM_OK);
}
