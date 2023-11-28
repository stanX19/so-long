#include "so_long.h"

static t_ani_sprite* get_animated_sprite(t_assets * assets, t_sp_data sp_data){
    t_sprite**		sprites_arr;
    t_image*		img;
	t_ani_sprite*	ret;

	if (!sp_data.rel_path)
		return 0;
	if (sp_data.size.x * sp_data.size.y <= 0)
	{
		ft_printf("ERROR: cat animated sprites: Invalid grid range for %s", sp_data.rel_path);
		return 0;
	}
	img = ft_read_xpm(assets, sp_data.rel_path);
    sprites_arr = ft_generate_sprites_array_rows(img, sp_data.start, sp_data.end, sp_data.size);
    ret = ft_init_animated_sprite(assets, sprites_arr, 32, 120);
	return ret;
}

t_ani_sprite*** ft_init_cat_ani_sprites(t_assets * assets) {
	t_ani_sprite*** ret;
	t_sp_data sp_data;

    ret = (t_ani_sprite ***)ft_malloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
                        		sizeof(t_ani_sprite**), sizeof(t_ani_sprite*));
	sp_data = (t_sp_data){"assets/sprites/cat/S_Idle.xpm", {0, 0}, {8, 4}, {8, 4}};
	for (int y = 0; y < NUM_DIRECTIONS; y++)
	{
        for (int x = 0; x < NUM_ACTIONS; x++)
		{
            ret[y][x] = 0;
		}
    }
	ret[LEFT][IDLE] = get_animated_sprite(assets, sp_data);
	ret[UP][IDLE] = ret[LEFT][IDLE];
	ret[DOWN][IDLE] = ret[LEFT][IDLE];
	return ret;
}