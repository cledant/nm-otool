/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_get_long_name_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:31:15 by cledant           #+#    #+#             */
/*   Updated: 2017/01/31 20:58:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

size_t		otool_get_long_name_size(const struct ar_hdr *start_header)
{
	int		i;
	char	tmp[16];

	i = 15;
	while (i > 2 && start_header->ar_name[i] != ' ')
		i--;
	if (i == 2)
		return (0);
	ft_bzero(tmp, 16);
	ft_memcpy(start_header->ar_name + 3, tmp, i - 2);
	return ((size_t)ft_atoi(tmp));
}
