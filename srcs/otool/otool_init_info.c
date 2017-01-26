/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_init_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:12:07 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 20:11:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	otool_init_info(t_info *info, const void *ptr, const off_t size)
{
	info->start = (size_t)ptr;
	info->file_size = size;
	info->endianness = BIG;
	info->end = info->start + info->file_size;
}
