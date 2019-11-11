#include "listlib.h"

static inline size_t	get_total_str_size(
							t_list const *list,
							size_t delim_len,
							int n,
							t_rostr (*get_str)(const void*, size_t))
{
	size_t	size;
	t_rostr	str;

	size = 0;
	for (; list && n > 0; LTONEXT(list), n--)
		if (list->content != NULL)
		{
			str = get_str(list->content, list->content_size);
			if (str)
				size += ft_strlen(str) + delim_len;
		}
	return size + 1;
}

/*
** Join n elements from the given list in a string.
*/

t_str					ft_lst_njoin(
							t_list const *list,
							t_rostr (*get_str)(const void*, size_t),
							t_rostr delim,
							int n)
{
	t_str			result;
	t_rostr			str;

	result = ft_strnew(get_total_str_size(list,
		(delim == NULL) ? 0 : ft_strlen(delim), n, get_str));

	if (result == NULL)
		return NULL;

	for (; list && n > 0; LTONEXT(list), n--)
		if (list->content != NULL)
		{
			str = get_str(list->content, list->content_size);
			if (str)
				ft_strcat(result, str);
			if (delim != NULL && !L_IS_LAST(list))
				ft_strcat(result, delim);
		}
	return result;
}
