/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:33:33 by cledant           #+#    #+#             */
/*   Updated: 2017/02/02 12:39:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_error_handler(const t_error err)
{
	if (err == ERR_ARGC)
		ft_putendl("ft_nm : argument number invalid");
	else if (err == ERR_OPEN)
		ft_putendl("ft_nm : error openning file");
	else if (err == ERR_FSTAT)
		ft_putendl("ft_nm : error getting file stats");
	else if (err == ERR_MMAP)
		ft_putendl("ft_nm : error allocating memory");
	else if (err == ERR_MUNMAP)
		ft_putendl("ft_nm : error releasing memory");
	else if (err == ERR_CLOSE)
		ft_putendl("ft_nm : error closing file");
	else if (err == ERR_INVALID_FILE)
		ft_putendl("ft_nm : error invalid file");
	else if (err == ERR_UNKNOWN)
		ft_putendl("ft_nm : error file type unknown");
	else if (err == ERR_MEM)
		ft_putendl("ft_nm : not enough memory");
	else if (err == ERR_NAME)
		ft_putendl("ft_nm : please enter a name");
	else if (err == ERR_INVALID_ARCHIVE)
		ft_putendl("ft_nm : error invalid archive");
	else if (err == ERR_NO_A_OUT)
		ft_putendl("ft_nm : a.out not found");
	return (NM_FAIL);
}
