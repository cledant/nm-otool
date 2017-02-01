/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_archive_explore.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:12:31 by cledant           #+#    #+#             */
/*   Updated: 2017/02/01 11:13:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_archive_explore(const struct ar_hdr *first, const size_t nb_item,
			const t_info *info)
{
	size_t			i;
	size_t			ex_size;
	size_t			header_size;
	char			*start_name;
	struct ar_hdr	*ptr;

	i = 0;
	ptr = (struct ar_hdr *)first;
	while (i < nb_item)
	{
		if (otool_is_interval_valid((size_t)ptr, sizeof(struct ar_hdr), info)
				== OTOOL_FAIL)
			return (otool_error_handler(ERR_INVALID_FILE));
		if (ft_strncmp(ptr->ar_name, AR_EFMT1, 3) == 0)
			return (otool_error_handler(ERR_INVALID_ARCHIVE));
		if ((ex_size = otool_get_long_name_size(ptr)) == 0)
			return (otool_error_handler(ERR_INVALID_ARCHIVE));
		if (otool_is_interval_valid((size_t)ptr, sizeof(struct ar_hdr) + ex_size,
				info) == OTOOL_FAIL)
			return (otool_error_handler(ERR_INVALID_FILE));
		if ((header_size = otool_get_header_size(ptr)) == 0)
			return (otool_error_handler(ERR_INVALID_ARCHIVE));
		if (otool_is_interval_valid((size_t)ptr, sizeof(struct ar_hdr) +
				header_size, info) == OTOOL_FAIL)
			return (otool_error_handler(ERR_INVALID_FILE));
		if ((start_name = otool_create_start_name(ptr, ex_size, info)) == NULL)
			return (otool_error_handler(ERR_MEM));
		if (otool_start(ptr + sizeof(struct ar_hdr) + ex_size,
				header_size - ex_size, start_name) == OTOOL_FAIL)
		{
			ft_strdel(&start_name);
			return (OTOOL_OK);
		}
		ptr = (void *)ptr + header_size + sizeof(struct ar_hdr);
		ft_strdel(&start_name);
		i++;
	}
	return (OTOOL_OK);
}
