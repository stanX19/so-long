#include "so_long.h"
#define NUM_DIRECTIONS 3
#define NUM_ACTIONS 3

typedef struct s_sprites_data
{
	char*	    path;
	t_vec2   size;

} t_sprites_data;

 void get_bee_paths(t_sprites_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS]) {
    sp_data[UP][DEATH] = (t_sprites_data){"assets/sprites/bee/U_Death.xpm", {6, 1}};
    sp_data[UP][WALK] = (t_sprites_data){"assets/sprites/bee/U_Walk.xpm", {6, 1}};
    sp_data[UP][ATTACK] = (t_sprites_data){0, {0, 0}};
    sp_data[DOWN][DEATH] = (t_sprites_data){"assets/sprites/bee/D_Death.xpm", {6, 1}};
    sp_data[DOWN][WALK] = (t_sprites_data){"assets/sprites/bee/D_Walk.xpm", {6, 1}};
    sp_data[DOWN][ATTACK] = (t_sprites_data){0, {0, 0}};
    sp_data[LEFT][DEATH] = (t_sprites_data){"assets/sprites/bee/S_Death.xpm", {6, 1}};
    sp_data[LEFT][WALK] = (t_sprites_data){"assets/sprites/bee/S_Walk.xpm", {6, 1}};
    sp_data[LEFT][ATTACK] = (t_sprites_data){0, {0, 0}};
}

static t_ani_sprite** get_animated_sprite(t_image* img, t_vec2 size){
    t_sprite** sprites_arr;
    
    sprites_arr = ft_generate_sprites_array(img, (t_vec2){0, 0}, size, size);
    return ft_init_animated_sprite(sprites_arr, size.x * size.y, 2);
}

t_ani_sprite*** ft_get_bee_ani_sprites(t_window_data* data) {
	t_ani_sprite*** ret;
    t_sprites_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS];
    t_image* img;

    ret = ft_malloc_2d(NUM_DIRECTIONS, NUM_ACTIONS,
                        sizeof(t_ani_sprite**), sizeof(t_ani_sprite*));
    get_bee_paths(sp_data);

    for (int y = 0; y < NUM_DIRECTIONS; y++) {
        for (int x = 0; x < NUM_ACTIONS; x++) {
            img = ft_read_xpm(data, sp_data[y][x].path);
            ret[y][x] = get_animated_sprite(img, sp_data[y][x].size);
        }
    }

	return ret;
}