/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_is_string_table_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:15:52 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 12:17:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_is_string_table_valid(const char *tab, const uint32_t size)
{
	if (tab[size - 1] != '\0')
		return (NM_FAIL);
	return (NM_OK);
}
