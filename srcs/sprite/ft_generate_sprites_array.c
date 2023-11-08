#include "so_long.h"

t_sprite**	ft_generate_sprites_array(t_image *image, t_vector2 start, t_vector2 end, t_vector2 grid_size){
	size_t		total_length;
	int			idx;
	t_sprite**	ret;

	total_length = (end.x - start.x) * (end.y - start.y);
	printf("%zu", total_length);
	ret = malloc(sizeof(t_sprite*) * total_length);
	idx = 0;
	for (int y = start.y; y < end.y; y++) {
		for (int x = start.x; x < end.x; x++) {
			ret[idx++] = ft_init_sprite(image, x, y, grid_size);
		}
	}

	return ret;
}