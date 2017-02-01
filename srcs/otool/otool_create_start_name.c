/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_create_start_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:10:19 by cledant           #+#    #+#             */
/*   Updated: 2017/02/01 19:26:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

char	*otool_create_start_name(const struct ar_hdr *ar_hdr, const size_t size,
			const t_info *info)
{
	size_t		real_size;
	size_t		arg_size;
	char		*real_name;
	char		*start_name;

	if ((real_size = otool_strnlen((void *)ar_hdr + sizeof(struct ar_hdr),
			size)) == 0)
		return (NULL);
	if ((real_name = ft_strnew(real_size)) == NULL)
		return (NULL);
	ft_memcpy(real_name, (void *)ar_hdr + sizeof(struct ar_hdr), real_size);
	arg_size = ft_strlen(info->arg);
	if ((start_name = ft_strnew(arg_size + 2 + real_size)) == NULL)
	{
		free(real_name);
		return (NULL);
	}
	ft_strcpy(start_name, info->arg);
	start_name[arg_size] = '(';
	ft_strcpy(start_name + arg_size + 1, real_name);
	start_name[arg_size + 1 + real_size] = ')';
	free(real_name);
	return (start_name);
}
