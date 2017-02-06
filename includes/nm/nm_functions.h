/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:16:57 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 13:05:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_FUNCTIONS_H
# define NM_FUNCTIONS_H

# include "nm_struct.h"

int			nm_start(const void *start_file, const off_t file_size,
				const char *arg);
int			nm_error_handler(const t_error err);
void		nm_init_info(t_info *info, const void *ptr, const off_t size,
				const char *arg);
int			nm_is_interval_valid(const size_t addr, const size_t size,
				const t_info *info);
void		nm_set_endianness(t_info *info, const uint32_t *start_file);

int			nm_is_string_tab_valid(const char *tab, const uint32_t size);
size_t		*nm_new_size_t_tab(size_t size);
int			nm_sort_symtab(size_t *sort_tab, const uint32_t nb_elmt,
				const char *tab, const struct nlist_64 *list);

int			nm_macho_64(const t_info *info,
				const struct mach_header_64 *start_macho);
int			nm_check_symtab_64(const struct symtab_command *symtab,
				const t_info *info, const struct mach_header_64 *start_macho);
int			nm_display_symtab_64(const struct mach_header_64 *start_macho,
				const struct symtab_command *symtab, const t_info *info,
				const size_t *sort_tab);
char		nm_get_sect_type_64(const uint8_t sect_val,
				const struct mach_header_64 *m_header, const t_info *info);
void		nm_display_symbol_value_type_64(const struct nlist_64 *data,
				const t_item item, const struct mach_header_64 *m_header,
				const t_info *info);
void		nm_init_symbol_info_64(t_symbol_info_64 *sy_info, const uint8_t val,
				const struct mach_header_64 *m_header, const t_info *info);
void		nm_print_undefined_64(const int uc);
void		nm_print_absolute_64(const int uc, const uint64_t value);
void		nm_print_sect_64(const int uc, const uint64_t value,
				const uint8_t sect_val, const t_symbol_info_64 *si);
void		nm_print_unknown_64(void);
void		nm_print_error_64(void);
void		nm_display_addr_64(const uint64_t num, const char *base);


int			nm_macho_32(const t_info *info,
				const struct mach_header *start_macho);
int			nm_check_symtab_32(const struct symtab_command *symtab,
				const t_info *info, const struct mach_header *start_macho);
int			nm_display_symtab_32(const struct mach_header *start_macho,
				const struct symtab_command *symtab, const t_info *info,
				const size_t *sort_tab);
char		nm_get_sect_type_32(const uint8_t sect_val,
				const struct mach_header *m_header, const t_info *info);
void		nm_display_symbol_value_type_32(const struct nlist *data,
				const t_item item, const struct mach_header *m_header,
				const t_info *info);
void		nm_init_symbol_info_32(t_symbol_info_32 *sy_info, const uint8_t val,
				const struct mach_header *m_header, const t_info *info);
void		nm_print_undefined_32(const int uc);
void		nm_print_absolute_32(const int uc, const uint32_t value);
void		nm_print_sect_32(const int uc, const uint32_t value,
				const uint8_t sect_val, const t_symbol_info_32 *si);
void		nm_print_unknown_32(void);
void		nm_print_error_32(void);
void		nm_display_addr_32(const uint32_t num, const char *base);

uint32_t	cvrt_u32(uint32_t num, const t_info *info);
uint64_t	cvrt_u64(uint64_t num, const t_info *info);

int			nm_fat_arch(const t_info *info,
				const struct fat_header *start_file);
void		nm_init_fat_info(t_fat_info *fat_info);
int			nm_check_fat_arch_x86_64(const t_info *info,
				const struct fat_header *start_file, t_fat_info *fat_info);
int			nm_check_fat_arch_x86(const t_info *info,
				const struct fat_header *start_file, t_fat_info *fat_info);
int			nm_fat_display_all(const t_info *info,
				const struct fat_header *start_file);
int			nm_fat_display_one(const struct fat_header *start_file,
				const t_fat_info *fat_info, const t_info *info);

int			nm_archive(const t_info *info,
				const struct ar_hdr *start_header);
size_t		nm_get_long_name_size(const struct ar_hdr *start_header);
size_t		nm_get_header_size(const struct ar_hdr *start_header);
size_t		nm_get_nb_item(const int *start_header);
int			nm_archive_explore(const struct ar_hdr *first,
				const size_t nb_item, const t_info *info);
char		*nm_create_start_name(const struct ar_hdr *ar_hdr, const size_t size,
				const t_info *info);
size_t		nm_strnlen(const char *s, size_t len);

#endif
