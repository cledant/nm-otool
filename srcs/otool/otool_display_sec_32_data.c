/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_display_sec_32_data.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:43:48 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 20:57:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_display_sec_32_data(const struct mach_header *start_header,
			const uint32_t offset, const uint32_t size, const t_info *info)
{
	unsigned char	*data;
	uint32_t		i;

	if (otool_is_interval_valid((size_t)(start_header + offset), size, info)
			== OTOOL_FAIL)
		return (OTOOL_FAIL);
	i = 0;
	data = (unsigned char *)(start_header + offset);
	while (i < size)
	{
		otool_itoa_base_stack((size_t)*data, "0123456789ABCDEF");
		i++;
		if (i < size)
			ft_putchar(' ');
	}
	ft_putendl("");
	return (OTOOL_OK);
}
