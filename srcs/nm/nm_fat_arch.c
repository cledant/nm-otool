/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat_arch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:07:14 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 22:24:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_fat_arch(const t_info *info,
			const struct fat_header *start_file)
{
	t_fat_info		fat_info;

	nm_init_fat_info(&fat_info);
	if (nm_check_fat_arch_x86_64(info, start_file, &fat_info) != NM_OK)
		return (NM_FAIL);
	if (fat_info.cpu == CPU_TYPE_ANY)
	{
		if (nm_check_fat_arch_x86(info, start_file, &fat_info) != NM_OK)
			return (NM_FAIL);
	}
	if (fat_info.cpu == CPU_TYPE_ANY)
		nm_fat_display_all(info, start_file);
	else
		nm_fat_display_one(start_file, &fat_info, info);
	return (NM_OK);
}
