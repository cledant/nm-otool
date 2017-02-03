/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_archive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:29:34 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 22:33:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		init_archive_explore(const t_info *info,
					const struct ar_hdr *start_header, const size_t ex_size)
{
	size_t		header_size;
	size_t		nb_item;

	if ((header_size = nm_get_header_size(start_header)) == 0)
		return (nm_error_handler(ERR_INVALID_ARCHIVE));
	if (nm_is_interval_valid((size_t)start_header + sizeof(struct ar_hdr),
			header_size, info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if ((nb_item = nm_get_nb_item((void *)start_header + ex_size +
			sizeof(struct ar_hdr))) == 0)
		return (nm_error_handler(ERR_INVALID_ARCHIVE));
	nm_archive_explore((void *)start_header + sizeof(struct ar_hdr)
		+ header_size, nb_item, info);
	return (NM_OK);
}

int				nm_archive(const t_info *info,
					const struct ar_hdr *start_header)
{
	size_t		ex_size;

	if (nm_is_interval_valid((size_t)start_header, sizeof(struct ar_hdr),
			info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	ft_putstr("Archive : ");
	ft_putendl(info->name);
	if (ft_strncmp(start_header->ar_name, AR_EFMT1, 3) != 0)
		return (NM_OK);
	if ((ex_size = nm_get_long_name_size(start_header)) == 0)
		return (nm_error_handler(ERR_INVALID_ARCHIVE));
	if (nm_is_interval_valid((size_t)start_header, sizeof(struct ar_hdr)
			+ ex_size, info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if (ft_strncmp((void *)start_header + sizeof(struct ar_hdr), SYMDEF,
			ft_strlen(SYMDEF)) != 0 && (ft_strncmp((void *)start_header +
			sizeof(struct ar_hdr), SYMDEF_SORTED, ft_strlen(SYMDEF_SORTED))
			!= 0))
		return (nm_error_handler(ERR_INVALID_ARCHIVE));
	init_archive_explore(info, start_header, ex_size);
	return (NM_OK);
}
