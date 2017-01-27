/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:15:00 by cledant           #+#    #+#             */
/*   Updated: 2017/01/27 11:16:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_FUNCTIONS_H
# define OTOOL_FUNCTIONS_H

#include "otool_struct.h"

int		otool_start(const void *start_file, const off_t file_size);
int		otool_error_handler(const t_error err);
void	otool_init_info(t_info *info, const void *ptr, const off_t size);
int		otool_is_mem_addr_valid(const t_info *info, const size_t addr);
int		otool_is_interval_valid(const size_t addr, const size_t size,
			const t_info *info);
void	otool_set_endianness(t_info *info, const uint32_t *start_file);
int		otool_macho_32(const t_info *info,
			const struct mach_header *start_macho);
int		otool_display_section_32(const struct mach_header *start_header,
			const struct segment_command *seg, const t_info *info);
int		otool_display_sec_32_data(const struct mach_header *start_header,
			const uint32_t offset, const uint32_t size, const t_info *info);
void	otool_itoa_base_stack(const unsigned char num, const char *base);
int		otool_macho_64(const t_info *info,
			const struct mach_header_64 *start_macho);
int		otool_display_section_64(const struct mach_header_64 *start_header,
			const struct segment_command_64 *seg, const t_info *info);
int		otool_display_sec_64_data(const struct mach_header_64 *start_header,
			const uint32_t offset, const uint64_t size, const t_info *info);

#endif
