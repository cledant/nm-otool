/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_get_sect_type_64.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:15:49 by cledant           #+#    #+#             */
/*   Updated: 2017/02/04 14:32:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	nm_get_sect_type_64(const uint8_t sect_val,
			const struct mach_header_64 *m_header)
{
	t_info					info;
	struct load_command		*lc;
	size_t					i;

	nm_set_endianness(&info, (void *)m_header);

	return ('E');
}
