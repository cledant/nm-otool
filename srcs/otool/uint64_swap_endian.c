/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint64_swap_endian.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:32:46 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 19:35:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

uint64_t	uint64_swap_endian(uint64_t num, const t_info *info)
{
	if (info->endian == BIG)
		return (num);
	return (num << 56);
}
