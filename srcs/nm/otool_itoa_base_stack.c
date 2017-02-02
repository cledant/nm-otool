/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_itoa_base_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:56:40 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 16:45:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	otool_itoa_base_stack(const unsigned char num, const char *base)
{
	char			display[16];
	size_t			size_base;
	size_t			i;
	unsigned char	cpy_num;

	cpy_num = num;
	if ((size_base = ft_strlen(base)) == 1)
		return ;
	if (cpy_num == 0)
		return (ft_putstr("00"));
	if (cpy_num < size_base)
		ft_putchar('0');
	ft_bzero(display, 16);
	i = 0;
	while (cpy_num != 0)
	{
		display[i] = base[cpy_num % size_base];
		cpy_num /= size_base;
		i++;
	}
	while (i != 0)
	{
		ft_putchar(display[i - 1]);
		i--;
	}
}
