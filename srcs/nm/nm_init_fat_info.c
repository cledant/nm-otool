/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_init_fat_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:11:34 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 22:11:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_init_fat_info(t_fat_info *fat_info)
{
	fat_info->cpu = CPU_TYPE_ANY;
	fat_info->size = 0;
	fat_info->offset = 0;
}
