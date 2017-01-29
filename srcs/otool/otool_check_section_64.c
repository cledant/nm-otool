/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_check_section_64.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:24:10 by cledant           #+#    #+#             */
/*   Updated: 2017/01/29 13:24:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_check_section_64(const struct mach_header_64 *start_header,
			const struct segment_command_64 *seg, const t_info *info)
{
	struct section_64	*sec;
	uint32_t			i;

	if (otool_is_interval_valid((size_t)seg, sizeof(struct segment_command_64),
			info) == OTOOL_FAIL)
		return (OTOOL_FAIL);
	i = 0;
	sec = (void *)seg + sizeof(struct segment_command_64);
	while (i < cvrt_u32(seg->nsects, info))
	{
		if (otool_is_interval_valid((size_t)sec, sizeof(struct section_64),
				info) == OTOOL_FAIL)
			return (OTOOL_FAIL);
		if (ft_strncmp(sec->segname, SEG_TEXT, 16) == 0 &&
				ft_strncmp(sec->sectname, SECT_TEXT, 16) == 0)
		{
			if (otool_display_sec_64_data(start_header, sec, info) == OTOOL_FAIL)
				return (OTOOL_FAIL);
		}
		sec = (void *)sec + sizeof(struct section_64);
		i++;
	}
	return (OTOOL_OK);
}
