/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_display_section_32.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:39:02 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 20:42:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

//GAFFE ENDIANNESS

int		otool_display_section_32(const struct mach_header *start_header,
			const struct segment_command *seg, const t_info *info)
{
	struct section	*sec;
	uint32_t		i;

	if (otool_is_interval_valid((size_t)seg, sizeof(struct segment_command),
			info) == OTOOL_FAIL)
		return (OTOOL_FAIL);
	i = 0;
	sec = (struct section *)seg + sizeof(struct segment_command);
	while (i < seg->nsects)  //ici
	{
		if (otool_is_interval_valid((size_t)sec, sizeof(struct section),
				info) == OTOOL_FAIL)
			return (OTOOL_FAIL);
		if (ft_strncmp(sec->segname, SEG_TEXT, 16) == 0 && //ici
				ft_strncmp(sec->sectname, SECT_TEXT, 16) == 0) //ici
		{
			if (otool_display_sec_32_data(start_header, sec->offset, //ici
					sec->size, info) == OTOOL_FAIL) //ici
				return (OTOOL_FAIL);
		}
		sec = sec + sizeof(struct section);
		i++;
	}
	return (OTOOL_OK);
}
