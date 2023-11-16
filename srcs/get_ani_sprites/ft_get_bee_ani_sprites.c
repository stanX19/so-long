#include "so_long.h"

static void get_bee_rel_paths(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS]) {
    sp_data[UP][DEATH] = (t_sp_data){"assets/sprites/bee/U_Death.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[UP][WALK] = (t_sp_data){"assets/sprites/bee/U_Walk.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[DOWN][DEATH] = (t_sp_data){"assets/sprites/bee/D_Death.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[DOWN][WALK] = (t_sp_data){"assets/sprites/bee/D_Walk.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[LEFT][DEATH] = (t_sp_data){"assets/sprites/bee/S_Death.xpm", {0, 0}, {6, 1}, {6, 1}};
    sp_data[LEFT][WALK] = (t_sp_data){"assets/sprites/bee/S_Walk.xpm", {0, 0}, {6, 1}, {6, 1}};
}

static t_ani_sprite* get_animated_sprite(t_mlx_data * data, t_sp_data sp_data){
    t_sprite**		sprites_arr;
    t_image*		img;
	t_ani_sprite*	ret;

	if (!sp_data.rel_path)
		return 0;
	if (sp_data.size.x * sp_data.size.y <= 0)
	{
		ft_printf("ERROR: Bee animated sprites: Invalid grid range for %s", sp_data.rel_path);
		return 0;
	}
	img = ft_read_xpm(data, sp_data.rel_path);
    sprites_arr = ft_generate_sprites_array_grid(img, sp_data.start, sp_data.end, sp_data.size);
    ret = ft_init_animated_sprite(data, sprites_arr, sp_data.size.x * sp_data.size.y, 10);
	return ret;
}

t_ani_sprite*** ft_get_bee_ani_sprites(t_mlx_data * data) {
	t_ani_sprite*** ret;
    t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS];

    ret = (t_ani_sprite ***)ft_malloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
                        		sizeof(t_ani_sprite**), sizeof(t_ani_sprite*));
	init_sp_data(sp_data);
    get_bee_rel_paths(sp_data);
    for (int y = 0; y < NUM_DIRECTIONS; y++)
	{
        for (int x = 0; x < NUM_ACTIONS; x++)
		{
            ret[y][x] = get_animated_sprite(data, sp_data[y][x]);
		}
    }
	ret[UP][IDLE] = ret[UP][WALK];
	ret[DOWN][IDLE] = ret[DOWN][WALK];
	ret[LEFT][IDLE] = ret[LEFT][WALK];
	return ret;
}