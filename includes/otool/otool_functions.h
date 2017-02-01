/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:15:00 by cledant           #+#    #+#             */
/*   Updated: 2017/02/01 11:00:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_FUNCTIONS_H
# define OTOOL_FUNCTIONS_H

# include "otool_struct.h"

int			otool_start(const void *start_file, const off_t file_size,
				const char *arg);
int			otool_error_handler(const t_error err);
void		otool_init_info(t_info *info, const void *ptr, const off_t size,
				const char *arg);
int			otool_is_mem_addr_valid(const t_info *info, const size_t addr);
int			otool_is_interval_valid(const size_t addr, const size_t size,
				const t_info *info);
void		otool_set_endianness(t_info *info, const uint32_t *start_file);

void		otool_itoa_base_stack(const unsigned char num, const char *base);

int			otool_macho_64(const t_info *info,
				const struct mach_header_64 *start_macho);
int			otool_check_section_64(const struct mach_header_64 *start_header,
				const struct segment_command_64 *seg, const t_info *info);
int			otool_display_sec_64_data(const struct mach_header_64 *start_header,
				const struct section_64 *sec, const t_info *info);
void		otool_display_text_addr_64(const uint64_t num,
				const uint64_t offset, const char *base);

int			otool_macho_32(const t_info *info,
				const struct mach_header *start_macho);
int			otool_check_section_32(const struct mach_header *start_header,
				const struct segment_command *seg, const t_info *info);
int			otool_display_sec_32_data(const struct mach_header *start_header,
				const struct section *sec, const t_info *info);
void		otool_display_text_addr_32(const uint32_t num,
				const uint32_t offset, const char *base);

uint32_t	cvrt_u32(uint32_t num, const t_info *info);
uint64_t	cvrt_u64(uint64_t num, const t_info *info);

int			otool_fat_arch(const t_info *info,
				const struct fat_header *start_file);
void		otool_init_fat_info(t_fat_info *fat_info);
int			otool_check_fat_arch_x86_64(const t_info *info,
				const struct fat_header *start_file, t_fat_info *fat_info);
int			otool_check_fat_arch_x86(const t_info *info,
				const struct fat_header *start_file, t_fat_info *fat_info);
int			otool_fat_display_all(const t_info *info,
				const struct fat_header *start_file);
int			otool_fat_display_one(const struct fat_header *start_file,
				const t_fat_info *fat_info, const t_info *info);

int			otool_archive(const t_info *info,
				const struct ar_hdr *start_header);
size_t		otool_get_long_name_size(const struct ar_hdr *start_header);
size_t		otool_get_header_size(const struct ar_hdr *start_header);
size_t		otool_get_nb_item(const size_t *start_header);
int			otool_archive_explore(const struct ar_hdr *first,
				const size_t nb_item, const t_info *info);
char		*otool_create_start_name(const struct ar_hdr *ar_hdr, const size_t size,
				const t_info *info);
size_t		otool_strnlen(const char *s, size_t len);

#endif
