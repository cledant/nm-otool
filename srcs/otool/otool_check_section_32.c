/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_check_section_32.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 14:43:15 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 16:04:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_check_section_32(const struct mach_header *start_header,
			const struct segment_command *seg, const t_info *info)
{
	struct section		*sec;
	uint32_t			i;

	if (otool_is_interval_valid((size_t)seg, sizeof(struct segment_command),
			info) == OTOOL_FAIL)
		return (OTOOL_FAIL);
	i = 0;
	sec = (void *)seg + sizeof(struct segment_command);
	while (i < cvrt_u32(seg->nsects, info))
	{
		if (otool_is_interval_valid((size_t)sec, sizeof(struct section),
				info) == OTOOL_FAIL)
			return (OTOOL_FAIL);
		if (ft_strncmp(sec->segname, SEG_TEXT, 16) == 0 &&
				ft_strncmp(sec->sectname, SECT_TEXT, 16) == 0)
		{
			if (otool_display_sec_32_data(start_header, sec, info)
					== OTOOL_FAIL)
				return (OTOOL_FAIL);
		}
		sec = (void *)sec + sizeof(struct section);
		i++;
	}
	return (OTOOL_OK);
}
