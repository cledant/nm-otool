/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_display_sec_32_data.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 14:59:21 by cledant           #+#    #+#             */
/*   Updated: 2017/01/29 14:59:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_display_sec_32_data(const struct mach_header *start_header,
			const struct section *sec, const t_info *info)
{
	unsigned char	*data;
	uint32_t		i;

	if (otool_is_interval_valid((size_t)start_header + cvrt_u32(sec->offset,
			info), cvrt_u32(sec->size, info), info) == OTOOL_FAIL)
		return (OTOOL_FAIL);
	i = 0;
	ft_putstr(info->arg);
	ft_putendl(":");
	ft_putendl("Contents of (__TEXT,__text) section");
	data = (void *)start_header + cvrt_u32(sec->offset, info);
	while (i < cvrt_u32(sec->size, info))
	{
		if (i % 16 == 0)
			otool_display_text_addr_32(cvrt_u32(sec->addr, info), i,
				"0123456789abcdef");
		otool_itoa_base_stack(*data, "0123456789abcdef");
		i++;
		data++;
		ft_putchar(' ');
		if (i % 16 == 0 && i < cvrt_u32(sec->size, info))
			ft_putchar('\n');
	}
	ft_putendl("");
	return (OTOOL_OK);
}
