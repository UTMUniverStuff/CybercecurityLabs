#include "hashtablib.h"
#include "ft_errors.h"

/*
** Assigns the newpair to an empry bucket. If there are no free buckets (cells)
** double the current size.
**
** Be careful to free the data yourself in case the htab doesn't accept
** to add the newpair (see not_enough_space_test.c)
*/

int		hashtab_add_pair(t_hashtab * const htab, t_hashpair * const newpair)
{
	size_t	pos;

	if (newpair == NULL)
		return (-1);
	if (htab->free_cells <= 0)
		htab_rehash(htab, (htab->tablen == 0) ? 2 : htab->tablen);
	pos = get_key_index(htab, newpair->key, 1);
	htab->tab[pos] = newpair;
	htab->free_cells--;
	return (0);
}

