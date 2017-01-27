/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_display_section_64.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:23:05 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 13:09:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

//GAFFE ENDIANNESS

int		otool_display_section_64(const struct mach_header_64 *start_header,
			const struct segment_command_64 *seg, const t_info *info)
{
	struct section_64	*sec;
	uint32_t			i;

	if (otool_is_interval_valid((size_t)seg, sizeof(struct segment_command_64),
			info) == OTOOL_FAIL)
		return (OTOOL_FAIL);
	i = 0;
	sec = (void *)seg + sizeof(struct segment_command_64);
	while (i < seg->nsects)  //ici
	{
		if (otool_is_interval_valid((size_t)sec, sizeof(struct section_64),
				info) == OTOOL_FAIL)
			return (OTOOL_FAIL);
		if (ft_strncmp(sec->segname, SEG_TEXT, 16) == 0 && //ici
				ft_strncmp(sec->sectname, SECT_TEXT, 16) == 0) //ici
		{
			if (otool_display_sec_64_data(start_header, sec, info) == OTOOL_FAIL)//ES
				return (OTOOL_FAIL);
		}
		sec = (void *)sec + sizeof(struct section_64);
		i++;
	}
	return (OTOOL_OK);
}
