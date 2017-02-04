/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_archive_explore.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:46:34 by cledant           #+#    #+#             */
/*   Updated: 2017/02/04 22:12:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		loop_check(t_arch_loop *arch, const t_info *info)
{
	if (nm_is_interval_valid((size_t)(arch->ptr), sizeof(struct ar_hdr),
			info) == NM_FAIL)
		return (NM_FAIL);
	if (ft_strncmp(arch->ptr->ar_name, AR_EFMT1, 3) != 0)
		return (nm_error_handler(ERR_INVALID_ARCHIVE));
	if ((arch->ex_size = nm_get_long_name_size(arch->ptr)) == 0)
		return (nm_error_handler(ERR_INVALID_ARCHIVE));
	if (nm_is_interval_valid((size_t)(arch->ptr), sizeof(struct ar_hdr)
			+ arch->ex_size, info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	if ((arch->header_size = nm_get_header_size(arch->ptr)) == 0)
		return (nm_error_handler(ERR_INVALID_ARCHIVE));
	if (nm_is_interval_valid((size_t)(arch->ptr), sizeof(struct ar_hdr) +
			arch->header_size, info) == NM_FAIL)
		return (nm_error_handler(ERR_INVALID_FILE));
	return (NM_OK);
}

static void		init_arch_loop(t_arch_loop *arch, const struct ar_hdr *first)
{
	arch->i = 0;
	arch->header_size = 0;
	arch->ex_size = 0;
	arch->ptr = (struct ar_hdr *)first;
	arch->start_name = NULL;
}

static void		disp_name(const char *name)
{
	ft_putstr(name);
	ft_putendl(":");
}

int				nm_archive_explore(const struct ar_hdr *first,
					const size_t nb_item, const t_info *info)
{
	t_arch_loop		arch;

	init_arch_loop(&arch, first);
	while (arch.i < nb_item)
	{
		ft_putchar('\n');
		if (loop_check(&arch, info) != NM_OK)
			return (NM_OK);
		if ((arch.start_name = nm_create_start_name(arch.ptr, arch.ex_size,
				info)) == NULL)
			return (nm_error_handler(ERR_MEM));
		disp_name(arch.start_name);
		if (nm_start((void *)(arch.ptr) + sizeof(struct ar_hdr) +
				arch.ex_size, arch.header_size - arch.ex_size, arch.start_name)
				== NM_FAIL)
		{
			ft_strdel(&(arch.start_name));
			return (NM_OK);
		}
		arch.ptr = (void *)(arch.ptr) + arch.header_size +
			sizeof(struct ar_hdr);
		ft_strdel(&(arch.start_name));
		(arch.i)++;
	}
	return (NM_OK);
}
