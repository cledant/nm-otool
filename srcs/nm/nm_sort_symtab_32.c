/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_sort_symtab_32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:17:42 by cledant           #+#    #+#             */
/*   Updated: 2017/02/06 14:17:59 by cledant          ###   ########.fr       */
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

static void		init_values(t_sort_symtab_val *val)
{
	val->i = 0;
	val->j = 0;
	val->ref = 0;
}

int				nm_sort_symtab_32(size_t *sort_tab, const uint32_t nb_elmt,
					const char *tab, const struct nlist *list)
{
	t_sort_symtab_val	val;
	char				*used_tab;

	if ((used_tab = ft_memalloc(nb_elmt)) == NULL)
		return (NM_FAIL);
	init_values(&val);
	while (set_ref(used_tab, nb_elmt, &(val.ref)) == NM_OK && val.i < nb_elmt)
	{
		while (val.j < nb_elmt)
		{
			if (used_tab[val.j] == UNUSED && ft_strcmp(tab +
				list[val.ref].n_un.n_strx, tab + list[val.j].n_un.n_strx) > 0)
			{
				val.ref = val.j;
				val.j = 0;
			}
			else
				(val.j)++;
		}
		sort_tab[val.i] = val.ref;
		used_tab[val.ref] = USED;
		val.j = 0;
		(val.i)++;
	}
	free(used_tab);
	return (NM_OK);
}
