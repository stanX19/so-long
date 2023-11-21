#include "so_long.h"

static void get_slime_rel_paths(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS]) {
    sp_data[UP][DEATH] = (t_sp_data){"assets/sprites/slime/U_Death.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[UP][WALK] = (t_sp_data){"assets/sprites/slime/U_Walk.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[DOWN][DEATH] = (t_sp_data){"assets/sprites/slime/D_Death.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[DOWN][WALK] = (t_sp_data){"assets/sprites/slime/D_Walk.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[LEFT][DEATH] = (t_sp_data){"assets/sprites/slime/S_Death.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[LEFT][WALK] = (t_sp_data){"assets/sprites/slime/S_Walk.xpm", {0, 0}, {6, 1}, {6, 1}};
}

static t_ani_sprite* get_animated_sprite(t_assets * assets, char * rel_path, t_vec2 size){
    t_sprite**		sprites_arr;
    t_image*		img;
	t_ani_sprite*	ret;

	if (!rel_path)
		return 0;
	if (size.x * size.y <= 0)
	{
		ft_printf("ERROR: Slime animated sprites: Invalid grid range for %s", rel_path);
		return 0;
	}
	img = ft_read_xpm(assets, rel_path);
    sprites_arr = ft_generate_sprites_array_grid(img, (t_vec2){0, 0}, size, size);
    ret = ft_init_animated_sprite(assets, sprites_arr, size.x * size.y, 10);
	return ret;
}

t_ani_sprite*** ft_init_slime_ani_sprites(t_assets * assets) {
	t_ani_sprite*** ret;
    t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS];

    ret = (t_ani_sprite ***)ft_malloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
                        		sizeof(t_ani_sprite**), sizeof(t_ani_sprite*));
	init_sp_data(sp_data);
    get_slime_rel_paths(sp_data);
    for (int y = 0; y < NUM_DIRECTIONS; y++) {
        for (int x = 0; x < NUM_ACTIONS; x++) {
            ret[y][x] = get_animated_sprite(assets, sp_data[y][x].rel_path, sp_data[y][x].size);
		}
    }
	ret[UP][IDLE] = ret[UP][WALK];
	ret[DOWN][IDLE] = ret[DOWN][WALK];
	ret[LEFT][IDLE] = ret[LEFT][WALK];
	return ret;
}