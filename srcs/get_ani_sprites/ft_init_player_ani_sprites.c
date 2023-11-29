#include "so_long.h"

static void get_player_rel_paths(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS])
{
	sp_data[DOWN][ATTACK] = (t_sp_data){"assets/sprites/player/D_Attack.xpm", {0, 0}, {1, 2}, {2, 2}};
    sp_data[DOWN][IDLE] = (t_sp_data){"assets/sprites/player/D_Idle.xpm", {0, 0}, {1, 2}, {4, 2}};
    sp_data[DOWN][WALK] = (t_sp_data){"assets/sprites/player/D_Walk.xpm", {0, 0}, {2, 2}, {4, 2}};
    sp_data[LEFT][ATTACK] = (t_sp_data){"assets/sprites/player/S_Attack.xpm", {0, 0}, {1, 2}, {2, 2}};
    sp_data[LEFT][IDLE] = (t_sp_data){"assets/sprites/player/S_Idle.xpm", {0, 0}, {1, 2}, {4, 2}};
    sp_data[LEFT][WALK] = (t_sp_data){"assets/sprites/player/S_Walk.xpm", {0, 0}, {2, 2}, {4, 2}};
	sp_data[UP][ATTACK] = (t_sp_data){"assets/sprites/player/U_Attack.xpm", {0, 0}, {1, 2}, {2, 2}};
    sp_data[UP][IDLE] = (t_sp_data){"assets/sprites/player/U_Idle.xpm", {0, 0}, {1, 2}, {4, 2}};
    sp_data[UP][WALK] = (t_sp_data){"assets/sprites/player/U_Walk.xpm", {0, 0}, {2, 2}, {4, 2}};
}

static int get_size(t_sp_data sp_data)
{
	return sp_data.start.x + sp_data.end.x +\
		(sp_data.end.y - sp_data.start.y - 1) * sp_data.size.x;
}

static t_ani_sprite* get_animated_sprite(t_assets * assets, t_sp_data sp_data)
{
    t_sprite**		sprites_arr;
    t_image*		img;
	t_ani_sprite*	ret;

	if (!sp_data.rel_path)
		return 0;
	if (sp_data.size.x * sp_data.size.y <= 0)
	{
		ft_printf("ERROR: player animated sprites: Invalid grid range for %s", sp_data.rel_path);
		return 0;
	}
	img = ft_read_xpm(assets, sp_data.rel_path);
    sprites_arr = ft_generate_sprites_array_rows(img, sp_data.start, sp_data.end, sp_data.size);
    ret = ft_init_animated_sprite(assets, sprites_arr, get_size(sp_data), 10);
	return ret;
}

t_ani_sprite*** ft_init_player_ani_sprites(t_assets * assets) {
	t_ani_sprite*** ret;
    t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS];

    ret = (t_ani_sprite ***)ft_calloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
                        		sizeof(t_ani_sprite**), sizeof(t_ani_sprite*));
	init_sp_data(sp_data);
    get_player_rel_paths(sp_data);
    for (int y = 0; y < NUM_DIRECTIONS; y++) {
        for (int x = 0; x < NUM_ACTIONS; x++) {
            ret[y][x] = get_animated_sprite(assets, sp_data[y][x]);
		}
    }
	return ret;
}