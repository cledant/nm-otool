/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_get_header_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:47:40 by cledant           #+#    #+#             */
/*   Updated: 2017/02/01 11:25:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

size_t		otool_get_header_size(const struct ar_hdr *start_header)
{
	int		i;
	char	tmp[16];

	i = 9;
	while (i >= 0 && start_header->ar_size[i] != ' ')
		i--;
	if (i < 0)
		return (0);
	ft_bzero(tmp, 16);
	ft_memcpy(tmp, (void *)(start_header->ar_size), i + 1);
	return ((size_t)ft_atoi(tmp));
}
