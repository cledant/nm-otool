/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:54:22 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 22:54:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		nm_strnlen(const char *s, size_t len)
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
