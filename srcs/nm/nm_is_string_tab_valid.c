/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_is_string_tab_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 12:13:11 by cledant           #+#    #+#             */
/*   Updated: 2017/02/04 12:18:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_is_string_tab_valid(const char *tab, const uint32_t size)
{
	if (tab[size - 1] != '\0')
		return (NM_FAIL);
	return (NM_OK);
}
