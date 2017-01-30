/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_display_text_addr_32.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:03:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 10:13:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	otool_display_text_addr_32(const uint32_t num, const uint32_t offset,
			const char *base)
{
	char			display[16];
	size_t			size_base;
	size_t			i;
	uint32_t		cpy_num;

	cpy_num = num + offset;
	if ((size_base = ft_strlen(base)) == 1)
		return ;
	ft_memset(display, '0', 16);
	i = 0;
	while (cpy_num != 0)
	{
		display[i] = base[cpy_num % size_base];
		cpy_num /= size_base;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		ft_putchar(display[7 - i]);
		i++;
	}
	ft_putchar('\t');
}
