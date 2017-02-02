/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_strnlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:36:10 by cledant           #+#    #+#             */
/*   Updated: 2017/02/01 10:45:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		otool_strnlen(const char *s, size_t len)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (i < len && *s != '\0')
	{
		length++;
		i++;
		s++;
	}
	return (length);
}
