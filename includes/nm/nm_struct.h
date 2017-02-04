/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:14:45 by cledant           #+#    #+#             */
/*   Updated: 2017/02/04 20:00:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_STRUCT_H
# define NM_STRUCT_H

typedef enum						e_error
{
	ERR_ARGC, ERR_OPEN, ERR_FSTAT, ERR_MMAP, ERR_MUNMAP, ERR_CLOSE,
	ERR_INVALID_FILE, ERR_UNKNOWN, ERR_MEM, ERR_NAME, ERR_INVALID_ARCHIVE,
	ERR_NO_A_OUT, ERR_SORT,
}									t_error;

typedef enum						e_endian
{
	BIG, LITTLE,
}									t_endian;

typedef struct						s_info
{
	size_t							start;
	off_t							file_size;
	t_endian						endian;
	size_t							end;
	const char						*arg;
	char							*name;
}									t_info;

typedef struct						s_fat_info
{
	cpu_type_t						cpu;
	uint32_t						size;
	uint32_t						offset;
}									t_fat_info;

typedef struct						s_arch_loop
{
	size_t							i;
	size_t							ex_size;
	size_t							header_size;
	char							*start_name;
	struct ar_hdr					*ptr;
}									t_arch_loop;

typedef struct						s_nm_info_64
{
	size_t							i;
	const struct mach_header_64		*m_header;
	const struct symtab_command		*symtab;
	const t_info					*info;
	const size_t					*sort_tab;
}									t_nm_info_64;

typedef struct						s_symbol_info
{
	uint8_t							stab;
	uint8_t							pext;
	uint8_t							type;
	uint8_t							ext;
	const struct mach_header_64		*m_header;
	const t_info					*info;
}									t_symbol_info;

typedef struct						s_sect_data
{
	char							type;
	size_t							counter;
	uint8_t							sect_val;
}									t_sect_data;

typedef struct						s_sort_symtab_val
{
	size_t							i;
	size_t							j;
	size_t							ref;
}									t_sort_symtab_val;	

typedef struct						s_item
{
	size_t							cur;
	size_t							max;
}									t_item;

#endif
