/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_get_sect_type_64.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:15:49 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 16:39:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void		compare_text(t_sect_data *data, const struct section_64 *sec)
{
	if (ft_strncmp(sec->sectname, SECT_TEXT, 16) == 0)
		data->type = 'T';
	else if (ft_strncmp(sec->sectname, SECT_BSS, 16) == 0)
		data->type = 'B';
	else if (ft_strncmp(sec->sectname, SECT_DATA, 16) == 0)
		data->type = 'D';
	else
		data->type = 'S';
}

static void		seek_sect(t_sect_data *data, const t_info *info,
					const struct segment_command_64 *seg)
{
	struct section_64	*sec;
	uint32_t			i;

	i = 1;
	sec = (void *)seg + sizeof(struct segment_command_64);
	while (i <= seg->nsects)
	{
		if (nm_is_interval_valid((size_t)sec, sizeof(struct section_64), info)
				== NM_FAIL)
			return ;
		if (data->counter + i == data->sect_val)
		{
			compare_text(data, sec);
			return ;
		}
		i++;
		sec = (void *)sec + sizeof(struct section_64);
	}
}

static int		is_in_interval(t_sect_data *data, const uint32_t nb)
{
	if (data->sect_val <= (data->counter + nb) &&
			data->sect_val > data->counter)
		return (YES);
	return (NO);
}

static int		seek_type(t_sect_data *data, const t_info *info,
					const struct segment_command_64 *seg)
{
	if (nm_is_interval_valid((size_t)seg, sizeof(struct segment_command_64),
			info) == NM_FAIL)
		return (NM_FAIL);
	if (is_in_interval(data, cvrt_u32(seg->nsects, info)) == YES)
	{
		seek_sect(data, info, seg);
		return (NM_OK);
	}
	data->counter += cvrt_u32(seg->nsects, info);
	return (NM_FAIL);
}

char			nm_get_sect_type_64(const uint8_t sect_val,
					const struct mach_header_64 *m_header, const t_info *info)
{
	struct load_command		*lc;
	uint32_t				i;
	t_sect_data				data;

	if (sect_val == 0)
		return ('E');
	i = 0;
	data.type = 'E';
	data.counter = 0;
	data.sect_val = sect_val;
	lc = (void *)m_header + sizeof(struct mach_header_64);
	while (i < cvrt_u32(m_header->ncmds, info))
	{
		if (nm_is_interval_valid((size_t)lc, sizeof(struct load_command), info)
				== NM_FAIL)
			return ('E');
		if (cvrt_u32(lc->cmd, info) == LC_SEGMENT_64)
		{
			if (seek_type(&data, info, (void *)lc) == NM_OK)
				return (data.type);
		}
		lc = (void *)lc + cvrt_u32(lc->cmdsize, info);
		i++;
	}
	return ('E');
}
