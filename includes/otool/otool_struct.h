/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:41:33 by cledant           #+#    #+#             */
/*   Updated: 2017/01/25 18:44:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_STRUCT_H
# define OTOOL_STRUCT_H

typedef enum		e_init_error
{
	ERR_ARGC, ERR_OPEN, ERR_FSTAT, ERR_MMAP, ERR_MUNMAP, ERR_CLOSE,
}					t_init_error;

#endif
