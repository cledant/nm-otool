/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:41:33 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 16:25:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_STRUCT_H
# define OTOOL_STRUCT_H

typedef enum		e_error
{
	ERR_ARGC, ERR_OPEN, ERR_FSTAT, ERR_MMAP, ERR_MUNMAP, ERR_CLOSE,
	ERR_INVALID_FILE, ERR_UNKNOWN, ERR_MEM
}					t_error;

typedef enum		e_endian
{
	BIG_ENDIAN, LITTLE_ENDIAN,
}					t_endian;

typedef struct		s_info
{
	size_t			start;
	off_t			file_size;
	t_endian		endianness;
	size_t			end;
}					t_info;

#endif
