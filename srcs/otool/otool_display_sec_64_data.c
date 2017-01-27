/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_display_sec_32_data.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:43:48 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 11:45:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_display_sec_64_data(const struct mach_header_64 *start_header,
			const uint32_t offset, const uint64_t size, const t_info *info)
{
	unsigned char	*data;
	uint64_t		i;

	if (otool_is_interval_valid((size_t)start_header + offset, size, info)
			== OTOOL_FAIL)
		return (OTOOL_FAIL);
	i = 0;
	data = (void *)start_header + offset; //ENDIANNESS ICI AUSSI
	while (i < size)
	{
		otool_itoa_base_stack(*data, "0123456789abcdef");
		i++;
		data++;
		(i % 16 == 0 && i < size) ? ft_putchar('\n') : ft_putchar(' ');
	}
	ft_putendl("");
	return (OTOOL_OK);
}
