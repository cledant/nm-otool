/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_check_archive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:05:01 by cledant           #+#    #+#             */
/*   Updated: 2017/01/30 13:18:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_check_archive(const void *start_file, const off_t file_size,
			const char *arg)
{
	if (file_size < 0 || file_size < (long long int)sizeof(uint32_t) ||
			file_size < (long long int)(sizeof(char) * 8))
		return (otool_error_handler(ERR_INVALID_FILE));
	if (ft_strncmp(start_file, "!<arch>\n", 8) == 0)
		otool_archive(start_file, file_size, arg);
	else
		otool_start(start_file, file_size, arg, OTOOL_CHECK_FAT);
	return (OTOOL_OK);
}
