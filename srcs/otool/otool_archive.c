/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_archive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:14:54 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 13:19:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_archive(const void *start_file, const off_t file_size,
			const char *arg)
{
	printf("start file = %lu\nsize = %lld\nname = %s\n", (size_t)start_file,
		file_size, arg);
	return (OTOOL_OK);
}
