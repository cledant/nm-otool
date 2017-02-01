/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_get_nb_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:00:43 by cledant           #+#    #+#             */
/*   Updated: 2017/02/01 11:12:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

size_t		otool_get_nb_item(const size_t *start_header)
{
	return (*start_header / sizeof(struct ranlib));
}
