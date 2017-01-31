/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_archive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:14:54 by cledant           #+#    #+#             */
/*   Updated: 2017/01/31 21:07:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static int		init_archive_explore(const t_info *info,
					const struct ar_hdr *start_header)
{
	size_t		header_size;
	size_t		nb_item;

	if ((header_size = otool_get_header_size(start_header)) == 0)
		return (otool_error_handler(ERR_ARCHIVE_INVALID));
	if (otool_is_interval_valid((size_t)start_header + sizeof(struct ar_hdr),
			header_size, info) == OTOOL_FAIL)
		return (otool_error_handler(ERR_INVALID_FILE));
	if ((nb_item = otool_get_nb_item((void *)start_header + ex_size +
			sizeof(struct ar_hdr))) == 0)
		return (otool_error_handler(ERR_ARCHIVE_INVALID));
	otool_archive_explore((void *)start_header + sizeof(struct ar_hdr)
		+ header_size, nb_item, info);
	return (OTOOL_OK);
}

int		otool_archive(const t_info *info, const struct ar_hdr *start_header)
{
	size_t		ex_size;

	if (otool_is_interval_valid((size_t)start_header, sizeof(struct ar_hdr),
			info) == OTOOL_FAIL)
		return (otool_error_handler(ERR_INVALID_FILE));
	ft_putstr("Archive : ");
	ft_putendl(info->name);
	if (ft_strcmp(start_header->name, AR_EFMT1, 3) != 0)
		return (OTOOL_OK);
	if ((ex_size = otool_get_long_name_size(start_header)) == 0)
		return (otool_error_handler(ERR_ARCHIVE_INVALID));
	if (otool_is_interval_valid((size_t)start_header, sizeof(struct ar_hdr)
			+ ex, info) == OTOOL_FAIL)
		return (otool_error_handler(ERR_INVALID_FILE));
	if (ft_strncmp((void *)start_header + sizeof(strucr ar_hdr), SYMDEF,
			ft_strlen(SYMDEF)) != 0 && (ft_strncmp((void *)start_header +
			sizeof(strucr ar_hdr), SYMDEF_SORTED, ft_strlen(SYMDEF_SORTED))
			!= 0))
		return (otool_error_handler(ERR_ARCHIVE_INVALID));
	init_archive_explore(info, start_header);
	return (OTOOL_OK);
}
