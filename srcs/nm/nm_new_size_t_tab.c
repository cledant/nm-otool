/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_new_size_t_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:21:34 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 12:24:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline size_t		*nm_new_size_t_tab(size_t size)
{
	size_t		*tab;

	if ((tab = (size_t *)malloc(sizeof(size_t) * size)) == NULL)
		return (NULL);
	ft_bzero(tab, sizeof(size_t) * size);
	return (tab);
}
