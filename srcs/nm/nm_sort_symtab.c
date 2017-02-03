/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_sort_symtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:24:44 by cledant           #+#    #+#             */
/*   Updated: 2017/02/03 14:24:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		set_ref(char *used_tab, const size_t nb_elmt, size_t *ref)
{
	size_t	i;

	i = 0;
	while (i < nb_elmt)
	{
		if (used_tab[i] == UNUSED)
		{
			*ref = i;
			return (NM_OK);
		}
		i++;	
	}
	return (NM_FAIL);	
}

int				nm_sort_symtab(size_t *sort_tab, const uint32_t nb_elmt,
					const char *tab)
{
	size_t	i;
	size_t	j;
	size_t	ref;
	char	*used_tab;

	if ((used_tab = ft_memalloc(nb_elmt)) == NULL)
		return (NM_FAIL);
	i = 0;
	j = 0;
	ref = 0;
	while (set_ref(used_tab, nb_elmt, &ref) == NM_OK && i < nb_elmt)
	{
		while (j < nb_elmt)
		{
			if (used_tab[j] == UNUSED && ft_strcmp(tab[ref], tab[j]) < 0)
			{
				ref = j;
				j = 0;
			}
			else
				j++;
		}
		sort_tab[i] = ref;
		used_tab[ref] = USED;
		j = 0;
		i++;
	}
	return (NM_OK);
}
