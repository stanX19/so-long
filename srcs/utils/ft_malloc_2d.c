#include "so_long.h"

void **	ft_calloc_2d(size_t height, size_t width, size_t pointer_size, size_t element_size)
{
	void** ret;

	ret = (void**)ft_calloc(height * pointer_size);
	if (ret == NULL)
	{
		return NULL;
	}
	ft_memset(ret, 0, sizeof(ret));
	for (size_t i = 0; i < height; i++)
	{
		ret[i] = (void *)ft_calloc(width * element_size);
		if (!ret[i])
		{
			ft_free_2d(ret, height);
			return 0;
		}
	}
    return ret;
}