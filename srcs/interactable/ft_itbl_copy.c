#include "so_long.h"

t_itbl * ft_itbl_copy(t_itbl *src)
{
	t_itbl *	ret;

	if (src == 0)
		return 0;
	ret = ft_calloc(sizeof(t_itbl));
	if (ret == 0)
		return 0;
	ft_memcpy(ret, src, sizeof(t_itbl));

	return ret;
}