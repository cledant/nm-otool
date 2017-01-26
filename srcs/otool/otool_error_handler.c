/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:37:18 by cledant           #+#    #+#             */
/*   Updated: 2017/01/26 20:17:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int		otool_error_handler(const t_error err)
{
	if (err == ERR_ARGC)
		ft_putendl("ft_otool : argument number invalid");
	else if (err == ERR_OPEN)
		ft_putendl("ft_otool : error openning file");
	else if (err == ERR_FSTAT)
		ft_putendl("ft_otool : error getting file stats");
	else if (err == ERR_MMAP)
		ft_putendl("ft_otool : error allocating memory");
	else if (err == ERR_MUNMAP)
		ft_putendl("ft_otool : error releasing memory");
	else if (err == ERR_CLOSE)
		ft_putendl("ft_otool : error closing file");
	else if (err == ERR_INVALID_FILE)
		ft_putendl("ft_otool : error invalid file");
	else if (err == ERR_UNKNOWN)
		ft_putendl("ft_otool : error file type unknown");
	else if (err == ERR_MEM)
		ft_putendl("ft_otool : not enough memory");
	return (OTOOL_FAIL);
}
