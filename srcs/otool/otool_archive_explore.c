/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_archive_explore.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:12:31 by cledant           #+#    #+#             */
/*   Updated: 2017/02/01 12:59:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static int		loop_check(t_arch_loop *arch, const t_info *info)
{
	if (otool_is_interval_valid((size_t)(arch->ptr), sizeof(struct ar_hdr),
			info) == OTOOL_FAIL)
		return (otool_error_handler(ERR_INVALID_FILE));
	if (ft_strncmp(arch->ptr->ar_name, AR_EFMT1, 3) != 0)
		return (otool_error_handler(ERR_INVALID_ARCHIVE));
	if ((arch->ex_size = otool_get_long_name_size(arch->ptr)) == 0)
		return (otool_error_handler(ERR_INVALID_ARCHIVE));
	if (otool_is_interval_valid((size_t)(arch->ptr), sizeof(struct ar_hdr)
			+ arch->ex_size, info) == OTOOL_FAIL)
		return (otool_error_handler(ERR_INVALID_FILE));
	if ((arch->header_size = otool_get_header_size(arch->ptr)) == 0)
		return (otool_error_handler(ERR_INVALID_ARCHIVE));
	if (otool_is_interval_valid((size_t)(arch->ptr), sizeof(struct ar_hdr) +
			arch->header_size, info) == OTOOL_FAIL)
		return (otool_error_handler(ERR_INVALID_FILE));
	return (OTOOL_OK);
}

static void		init_arch_loop(t_arch_loop *arch, const struct ar_hdr *first)
{
	arch->i = 0;
	arch->header_size = 0;
	arch->ex_size = 0;
	arch->ptr = (struct ar_hdr *)first;
	arch->start_name = NULL;
}

int				otool_archive_explore(const struct ar_hdr *first,
					const size_t nb_item, const t_info *info)
{
	t_arch_loop		arch;

	init_arch_loop(&arch, first);
	while (arch.i < nb_item)
	{
		loop_check(&arch, info);
		if ((arch.start_name = otool_create_start_name(arch.ptr, arch.ex_size,
				info)) == NULL)
			return (otool_error_handler(ERR_MEM));
		if (otool_start((void *)(arch.ptr) + sizeof(struct ar_hdr) +
				arch.ex_size, arch.header_size - arch.ex_size, arch.start_name)
				== OTOOL_FAIL)
		{
			ft_strdel(&(arch.start_name));
			return (OTOOL_OK);
		}
		arch.ptr = (void *)(arch.ptr) + arch.header_size +
			sizeof(struct ar_hdr);
		ft_strdel(&(arch.start_name));
		(arch.i)++;
	}
	return (OTOOL_OK);
}
