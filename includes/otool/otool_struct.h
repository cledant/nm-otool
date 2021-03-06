/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:41:33 by cledant           #+#    #+#             */
/*   Updated: 2017/02/01 12:44:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_STRUCT_H
# define OTOOL_STRUCT_H

typedef enum		e_error
{
	ERR_ARGC, ERR_OPEN, ERR_FSTAT, ERR_MMAP, ERR_MUNMAP, ERR_CLOSE,
	ERR_INVALID_FILE, ERR_UNKNOWN, ERR_MEM, ERR_NAME, ERR_INVALID_ARCHIVE,
}					t_error;

typedef enum		e_endian
{
	BIG, LITTLE,
}					t_endian;

typedef struct		s_info
{
	size_t			start;
	off_t			file_size;
	t_endian		endian;
	size_t			end;
	const char		*arg;
	char			*name;
}					t_info;

typedef struct		s_fat_info
{
	cpu_type_t		cpu;
	uint32_t		size;
	uint32_t		offset;
}					t_fat_info;

typedef struct		s_arch_loop
{
	size_t			i;
	size_t			ex_size;
	size_t			header_size;
	char			*start_name;
	struct ar_hdr	*ptr;
}					t_arch_loop;

#endif
