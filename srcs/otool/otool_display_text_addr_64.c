/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_display_text_addr_64.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:16:13 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 17:16:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	otool_display_text_addr_64(const uint64_t num, const uint64_t offset,
			const char *base)
{
	char			display[16];
	size_t			size_base;
	size_t			i;
	uint64_t		cpy_num;

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
	while (i < 16)
	{
		ft_putchar(display[15 - i]);
		i++;
	}
	ft_putchar('\t');
}
