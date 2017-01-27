/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_display_sec_32_data.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:43:48 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 17:17:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_display_sec_64_data(const struct mach_header_64 *start_header,
			const struct section_64 *sec, const t_info *info)
{
	unsigned char	*data;
	uint64_t		i;

	if (otool_is_interval_valid((size_t)start_header + sec->offset, sec->size,
			info) == OTOOL_FAIL)
		return (OTOOL_FAIL);
	i = 0;
	ft_putstr(info->arg);
	ft_putendl(":");
	ft_putendl("Contents of (__TEXT,__text) section");
	data = (void *)start_header + sec->offset; //ENDIANNESS ICI AUSSI
	while (i < sec->size)
	{
		if (i % 16 == 0)
			otool_display_text_addr_64(sec->addr, i, "0123456789abcdef");
		otool_itoa_base_stack(*data, "0123456789abcdef");
		i++;
		data++;
		ft_putchar(' ');
		if (i % 16 == 0 && i < sec->size)
			ft_putchar('\n');
	}
	ft_putendl("");
	return (OTOOL_OK);
}
