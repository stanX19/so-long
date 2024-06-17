/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:30:33 by shatan            #+#    #+#             */
/*   Updated: 2024/06/17 15:46:21 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define NUM_DIRECTIONS 4
# define NUM_ACTIONS 4
# include "assets_path.h"
# include "configs.h"
# include "libft.h"
# include "trgb_colors.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef union s_color
{
	unsigned int		trgb;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	t;
	};
}						t_color;

typedef struct s_image
{
	void				*mlx;
	void				*img;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	char				*addr;
	int					width;
	int					height;
}						t_image;

typedef struct s_node
{
	void				*ptr;
	void				*next;
}						t_node;

typedef struct s_linked_list
{
	t_node				*head;
}						t_linked_list;

typedef struct s_window
{
	void				*mlx;
	void				*mlx_win;
	char				*title;
	size_t				width;
	size_t				height;
}						t_window;

typedef struct s_sprite
{
	int					width;
	int					height;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
}						t_sprite;

typedef struct s_animated_sprite
{
	t_sprite			**sprites_arr;
	int					length;
	int					frame_interval;
	t_vec2				offset;
}						t_ani_sprite;

typedef struct s_grouped_sp
{
	t_sprite			*path_wall[16];
	t_sprite			*water_path[16];
	t_sprite			*path_tree[16];
	t_sprite			*all_grass[16];
}						t_grouped_sp;

typedef enum s_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}						t_direction;

typedef enum s_sprite_status
{
	DEATH,
	WALK,
	ATTACK,
	IDLE,
}						t_sprite_status;

typedef enum s_itbl_status
{
	IDLING = (0),
	DYING = (1 << 0),
	DEAD = (1 << 1),
	MOVING = (1 << 2),
	ATTACKING = (1 << 3)
}						t_itbl_status;

typedef struct s_stats
{
	int					speed;
	int					base_speed;
	int					steps;
	int					hp;
}						t_stats;

typedef struct s_sp_data
{
	char				*rel_path;
	t_vec2				start;
	t_vec2				end;
	t_vec2				size;
}						t_sp_data;
// sprite_tab[direction][status]

typedef enum s_tile
{
	TILE_PATH = (1 << 0),
	TILE_WALL = (1 << 1),
	TILE_WATER = (1 << 2),
	TILE_EXIT = (1 << 3),
	TILE_PLAYER = (1 << 4),
	TILE_COLLECTIBLE = (1 << 5),
	TILE_ENEMY = (1 << 6),
	TILE_ENEMY_ATK = (1 << 7),
	TILE_ALLY = (1 << 8),
	TILE_ALLY_ATK = (1 << 9),
	TILE_WOLF = (1 << 10),
	TILE_WOLF_ATK = (1 << 11),
	TILE_GOBLIN = (1 << 12),
	TILE_GOBLIN_ATK = (1 << 13),
	TILE_CAT = (1 << 14),
	TILE_PORTAL = (1 << 15),
	TILE_COIN = (1 << 16),
	TILE_HUMAN = (1 << 17),
	TILE_SLIME = (1 << 18),
	TILE_BEE = (1 << 19),
	TILE_VISITED = (1 << 20)
}						t_tile;

typedef struct s_itbl
{
	t_vec2				cord;
	t_vec2				rel_cord;
	t_vec2				velocity;
	t_direction			direction;
	t_ani_sprite		*animation;
	t_sprite_status		sp_status;
	t_itbl_status		status;
	int					_flip;
	t_tile				self;
	t_tile				blocking;
	t_tile				faction;
	t_tile				enemy;
	t_tile				attack;
	t_ani_sprite		***sprite_tab;
	bool				can_atk;
	int					sprite_idx;
	int					frame_tick;
	t_stats				stats;
}						t_itbl;

typedef struct s_itbl_dict
{
	char				key;
	t_tile				faction;
	t_tile				background;
	t_itbl				*itbl;
}						t_itbl_dict;

typedef struct s_itbl_cfg
{
	int					base_spd;
	t_tile				self;
	t_tile				blocking;
	int					hp;
}						t_itbl_cfg;

typedef struct s_ani_assets
{
	t_ani_sprite		***slime;
	t_ani_sprite		***slime2;
	t_ani_sprite		***bee;
	t_ani_sprite		***coin;
	t_ani_sprite		***human;
	t_ani_sprite		***wolf;
	t_ani_sprite		***goblin;
	t_ani_sprite		***portal;
	t_ani_sprite		***cat;
}						t_ani_assets;

typedef struct s_assets
{
	void				*mlx;
	t_linked_list		all_img;
	t_linked_list		all_ani_sprite;
	t_itbl				*bee;
	t_itbl				*slime;
	t_itbl				*slime2;
	t_itbl				*coin;
	t_itbl				*human;
	t_itbl				*wolf;
	t_itbl				*goblin;
	t_itbl				*portal;
	t_itbl				*cat;
	t_ani_assets		ani_tabs;
	t_sprite			**all_tile;
	size_t				all_tile_len;
	t_grouped_sp		tiles;
	t_vec2				tile_size;
}						t_assets;

enum					e_event_type
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum					e_x11_event_masks
{
	NO_EVENT_MASK = (0L),
	KEY_PRESS_MASK = (1L << 0),
	KEY_RELEASE_MASK = (1L << 1),
	BUTTON_PRESS_MASK = (1L << 2),
	BUTTON_RELEASE_MASK = (1L << 3),
	ENTER_WINDOW_MASK = (1L << 4),
	LEAVE_WINDOW_MASK = (1L << 5),
	POINTER_MOTION_MASK = (1L << 6),
	POINTER_MOTION_HINT_MASK = (1L << 7),
	BUTTON1_MOTION_MASK = (1L << 8),
	BUTTON2_MOTION_MASK = (1L << 9),
	BUTTON3_MOTION_MASK = (1L << 10),
	BUTTON4_MOTION_MASK = (1L << 11),
	BUTTON5_MOTION_MASK = (1L << 12),
	BUTTON_MOTION_MASK = (1L << 13),
	KEYMAP_STATE_MASK = (1L << 14),
	EXPOSURE_MASK = (1L << 15),
	VISIBILITY_CHANGE_MASK = (1L << 16),
	STRUCTURE_NOTIFY_MASK = (1L << 17),
	RESIZE_REDIRECT_MASK = (1L << 18),
	SUBSTRUCTURE_NOTIFY_MASK = (1L << 19),
	SUBSTRUCTURE_REDIRECT_MASK = (1L << 20),
	FOCUS_CHANGE_MASK = (1L << 21),
	PROPERTY_CHANGE_MASK = (1L << 22),
	COLORMAP_CHANGE_MASK = (1L << 23),
	OWNER_GRAB_BUTTON_MASK = (1L << 24),
};

typedef struct s_input
{
	int					keyboard[128];
	int					mouse_left;
	int					mouse_right;
}						t_input;

typedef struct s_itbl_arr
{
	t_itbl				**arr;
	size_t				len;
}						t_itbl_arr;

typedef struct s_map
{
	t_tile				**grid;
	t_vec2				grid_size;
	t_image				*bkg_img;
	t_itbl				*player;
	t_itbl				*exit;
	t_itbl_arr			coins;
	t_itbl_arr			enemies;
	t_assets			*assets;
	struct s_raw
	{
		char			**grid;
		int				width;
		int				height;
	}					raw;
}						t_map;

typedef struct s_map_dfs_args
{
	t_map				*map;
	t_tile				target;
	t_tile				blocking;
	int					depth;
}						t_map_bfs_args;

typedef struct s_default_tileset_gen_vars
{
	t_image				*img;
	t_vec2				size;
	int					y;
	int					x;
	unsigned int		color_0;
	unsigned int		color_1;
}						t_default_tileset_gen_vars;

typedef enum e_game_status
{
	STATE_RUNNING,
	STATE_QUIT,
	STATE_RESET,
	STATE_NEXT_GAME,
}						t_game_status;

typedef struct s_vars
{
	void				*mlx;
	t_assets			*assets;
	t_map				*map;
	t_image				*base_img;
	t_window			*window;
	t_input				*input;
	char				**paths;
	char				*title;
	int					paths_len;
	int					idx;
	t_game_status		state;
}						t_vars;

void					ft_list_add(t_linked_list *list, void *ptr);
void					ft_list_remove(t_linked_list *list, void *ptr);
void					ft_free_list(t_linked_list *list,
							void (*free_func)(void *));

t_image					*ft_read_xpm(t_assets *assets, char *relative_path);
t_image					*ft_new_image(t_assets *assets, int width, int height);
t_image					*ft_new_colored_image(t_assets *assets, int width,
							int height, unsigned int color);
void					ft_fill_image(t_image *img, unsigned int color,
							t_vec2 start, t_vec2 end);
void					ft_fill_image_whole(t_image *img, unsigned int color);
int						ft_mlx_loop_hook(t_vars *vars, int (*funct_ptr)());
int						ft_mlx_put_image_to_win(t_window *window, t_image *img,
							int x, int y);
void					ft_mlx_put_img_to_img(t_image *dst, t_image *src,
							int img_x, int img_y);
void					ft_image_destory(t_image *image);

void					ft_mlx_pixel_put(t_image *img, int x, int y,
							unsigned int color);
t_window				*ft_mlx_init(void);
void					ft_mlx_destory(void *mlx);
t_window				*ft_window_init(void *mlx, int width, int height,
							char *title);
void					ft_window_destory(t_window *window);
void					ft_mlx_clear_window(t_window *window);

char					**ft_raw_map_copy(char *const *map, int width,
							int height);
char					*ft_has_invalid_pathway(char **map, int width,
							int height);
const char				*ft_is_invalid_map_file(const char *path);
bool					ft_check_argv_validity(char *const *paths, int len);
char					**ft_generate_raw_map(const char *path, size_t *width,
							size_t *height);
char					**ft_gen_raw_map_safe(const char *path, size_t *width,
							size_t *height);

void					ft_config_default_itbl(t_assets *assets);
const t_itbl_dict		*ft_get_itbl_dict(t_assets *assets);
const t_itbl_dict		*ft_get_itbl_hash(t_assets *assets);
char					*ft_get_accepted_charset(void);
char					*ft_get_enemy_charset(void);
void					ft_map_init_ibtl(t_map *map);
t_image					*ft_map_bg_gen(t_map *map, t_assets *assets);
t_map					*ft_map_init(const char *path, t_assets *assets);
void					ft_map_destory(t_map *map);
void					ft_map_reset(t_map	*map);
void					ft_map_put_itbl(t_image *img, t_map *map,
							t_vec2 offset);
void					ft_map_update_itbl(t_map *map);
void					ft_map_update_itbl_pos(t_map *map);
void					ft_map_check_reaction(t_map *map, t_vec2 cord);
void					ft_map_update_all_status(t_map *map);
bool					ft_map_itbl_check_death(t_map *map, t_itbl *itbl);
void					ft_map_itbl_pos_add(t_map *map, t_itbl *itbl,
							t_tile val);
void					ft_map_itbl_front_add(t_map *map, t_itbl *itbl,
							t_tile val);
void					ft_map_check_rel_cord(t_map *map, t_itbl *itbl);
void					ft_map_check_velocity(t_map *map, t_itbl *itbl);
void					ft_map_update_enemy_v(t_map *map);
t_vec2					ft_map_bfs_target_tile(t_map_bfs_args args,
							t_vec2 start);
t_vec2					ft_get_displayed_cord(t_vec2 tile_size, t_itbl *itbl);

t_sprite				*ft_init_sprite(t_image *img, int x, int y,
							t_vec2 grid_size);
t_sprite				**ft_generate_sprites_array_grid(t_image *image,
							t_vec2 start, t_vec2 end, t_vec2 grid_size);
t_sprite				**ft_generate_sprites_array_rows(t_image *image,
							t_vec2 end, t_vec2 grid_size);
t_ani_sprite			*ft_init_animated_sprite(t_assets *assets,
							t_sprite **sprites, int length, int frame_interval);
void					ft_mlx_put_sprite(t_image *image, t_sprite *sprite,
							int x, int y);
void					ft_sprite_destory(t_sprite *sprite);
void					ft_ani_sprite_destory(t_ani_sprite *animated);

void					init_sp_data(
							t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS]);
t_ani_sprite			*ft_gen_default_ani_sp(t_assets *assets,
							unsigned int color);
t_ani_sprite			***ft_init_bee_ani_sprites(t_assets *assets);
t_ani_sprite			***ft_init_slime_ani_sprites(t_assets *assets);
t_ani_sprite			***ft_init_slime2_ani_sprites(t_assets *assets);
t_ani_sprite			***ft_init_human_ani_sprites(t_assets *assets);
t_ani_sprite			***ft_init_coin_ani_sprites(t_assets *assets);
t_ani_sprite			***ft_init_cat_ani_sprites(t_assets *assets);
t_ani_sprite			***ft_init_wolf_ani_sprites(t_assets *assets);
t_ani_sprite			***ft_init_goblin_ani_sprites(t_assets *assets);
t_ani_sprite			***ft_init_portal_ani_sprites(t_assets *assets);

t_itbl					*ft_init_interactable(t_ani_sprite ***sprite_tab);
void					ft_put_interactable_to_img(t_image *base_img,
							t_itbl *itbl, int x, int y);
void					ft_mlx_put_sprite_reverse(t_image *image,
							t_sprite *sprite, int img_x, int img_y);
void					ft_itbl_reset_ani(t_itbl *itbl);
void					ft_itbl_update_frame(t_itbl *itbl);
void					ft_itbl_destory(t_itbl *itbl);
void					ft_itbl_set_status(t_itbl *itbl, t_itbl_status status);
void					ft_itbl_set_faction(t_itbl *itbl, t_tile faction);
t_itbl					*ft_itbl_copy(t_itbl *src);
void					ft_itbl_update_direction(t_itbl *itbl);
void					ft_itbl_config(t_itbl *itbl, t_itbl_cfg params);

t_input					*ft_init_input(void);
void					ft_input_destory(t_input *input);
int						ft_has_input(t_input *input);
int						ft_on_key_press(int keycode, t_vars *vars);
int						ft_on_key_release(int keycode, t_vars *vars);
int						ft_on_mouse_click(int button, int x, int y,
							t_vars *vars);
int						ft_on_mouse_release(int button, int x, int y,
							t_vars *vars);
int						ft_on_destory(t_vars *vars);
void					ft_hook_listeners(t_vars *vars);

t_image					*ft_default_tileset_gen(t_assets *assets, t_vec2 size);
t_sprite				**ft_init_line_fmt_tileset(t_assets *assets,
							char *path);
t_assets				*ft_init_assets(void *mlx);
void					ft_destory_assets(t_assets *assets);

t_vars					*ft_init_vars(int argc, char **argv);
void					ft_init_game(t_vars *vars);
void					ft_delete_game(t_vars *vars);
void					ft_delete_vars(t_vars *vars);
void					ft_new_game(t_vars *vars);
void					ft_reset_game(t_vars *vars);
void					ft_next_game(t_vars *vars);
void					ft_game_display(t_vars *vars);
int						ft_end_program(t_vars *vars);
int						ft_main_loop(t_vars *vars);

int						ft_get_dash_status(t_input *input);
void					ft_update_player(t_vars *vars);
void					ft_show_steps(t_vars *vars);
void					ft_print_steps(t_vars *vars, char *fmt_str);
#endif
