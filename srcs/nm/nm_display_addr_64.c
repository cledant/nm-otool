/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_display_addr_64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:08:14 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 17:31:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	nm_display_addr_64(const uint64_t num, const char *base)
{
	char			display[16];
	size_t			size_base;
	size_t			i;
	uint64_t		cpy_num;

	cpy_num = num;
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
	ft_putchar(' ');
}
