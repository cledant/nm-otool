/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_init_symbol_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:03:05 by cledant           #+#    #+#             */
/*   Updated: 2017/02/04 19:27:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline static uint8_t	get_stab(const uint8_t val)
{
	uint8_t		cpy_val;

	cpy_val = val >> 5;
	return (cpy_val);
}

inline static uint8_t	get_pext(const uint8_t val)
{
	uint8_t		cpy_val;

	cpy_val = (val & 0x10) >> 4;
	return (cpy_val);
}

inline static uint8_t	get_type(const uint8_t val)
{
	uint8_t		cpy_val;

	cpy_val = (val & 0x0e);
	return (cpy_val);
}

inline static uint8_t	get_ext(const uint8_t val)
{
	uint8_t		cpy_val;

	cpy_val = (val & 0x01);
	return (cpy_val);
}

void					nm_init_symbol_info(t_symbol_info *sy_info,
							const uint8_t val,
							const struct mach_header_64 *m_header,
							const t_info *info)
{
	sy_info->stab = get_stab(val);
	sy_info->pext = get_pext(val);
	sy_info->type = get_type(val);
	sy_info->ext = get_ext(val);
	sy_info->m_header = m_header;
	sy_info->info = info;
}
