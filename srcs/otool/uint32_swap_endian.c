/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint32_swap_endian.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:04:28 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 18:21:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

inline uint32_t		uint32_swap_endian(uint32_t num, const t_info *info)
{
	if (info->endian == BIG)
		return (num);
	return (num << 24 | (num << 8 & 0x00FF0000) | (num >> 8 & 0x0000FF00) |
				(num >> 24 & 0x000000FF));
}
