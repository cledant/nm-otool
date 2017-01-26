/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_itoa_base_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:56:40 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 20:58:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	otool_itoa_base_stack(size_t num, const char *base)
{
	char	display[256];
	size_t	size_base;
	size_t	i;

	if (num == 0)
		return (ft_putchar('0'));
	if ((size_base = ft_strlen(base)) == 1)
		return ;
	ft_bzero(display, 256);
	i = 0;
	while (num != 0)
	{
		display[i] = base[num % size_base];
		num /= size_base;
		i++;
	}
	while (i != 0)
	{
		ft_putchar(display[i - 1]);
		i--;
	}
}
