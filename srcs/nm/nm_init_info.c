/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:49:59 by cledant           #+#    #+#             */
/*   Updated: 2017/02/02 12:50:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_init_info(t_info *info, const void *ptr, const off_t size,
							const char *arg)
{
	info->start = (size_t)ptr;
	info->file_size = size;
	info->endian = BIG;
	info->end = info->start + info->file_size;
	info->arg = arg;
	info->name = NULL;
}
