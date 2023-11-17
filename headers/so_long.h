#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H
# define MAX_FREE_ARR_SIZE 100
# define NUM_DIRECTIONS 4
# define NUM_ACTIONS 4
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>

typedef struct s_vec2 {
	int x;
	int y;
} t_vec2;

typedef union s_color {
	unsigned int trgb;
	struct {
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char t;
	};
} t_color;

typedef struct	s_image {
	void*	img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	int		width;
	int		height;
} t_image;

typedef struct s_free_arr {
	void * arr[MAX_FREE_ARR_SIZE];
	int idx;
} t_free_arr;

typedef struct	s_mlx_data {
	void *		mlx;
	void *		mlx_win;
	size_t		width;
	size_t		height;
	t_free_arr	all_img;
	t_free_arr	all_ani_sprite;
}				t_mlx_data;

typedef struct	s_sprite {
	int		width;
	int		height;
	char*	addr;
	int		bits_per_pixel;
	int		line_length;
} t_sprite;

typedef struct	s_animated_sprite {
	t_sprite	**sprites_arr;
	int			length;
	int			frame_interval;
} t_ani_sprite;

typedef enum s_direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
} t_direction;

typedef enum s_sprite_status {
	DEATH,
	WALK,
	ATTACK,
	IDLE,
} t_sprite_status;

typedef enum s_itbl_status {
	DYING,
	DEAD,
	IDLING,
	MOVING,
	ATTACKING,
} t_itbl_status;

typedef struct	s_stats{
	int	damage;
	int	health;
	int max_health;
	int	speed;
	int atk_cd;
} t_stats;

typedef struct s_sp_data
{
	char *	rel_path;
	t_vec2	start;
	t_vec2	end;
	t_vec2  size;
} t_sp_data;
// sprite_tab[direction][status]
typedef struct	s_itbl {
	t_vec2				loc;
	t_vec2				rel_cords;
	t_direction			direction;
	t_ani_sprite *		animation;
	t_sprite_status		sp_status;
	t_itbl_status		status;
	int					flip;
	t_ani_sprite ***	sprite_tab;
	int					sprite_idx;
	int					frame_tick;
	t_stats				stats;
} t_itbl;

typedef enum {
    PATH,
    WALL,
    WATER
} t_tile;

enum s_event_type {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum s_x11_event_masks {
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

typedef struct s_input {
    int	keyboard[128];
    int	esc_code;
	int	mouse_left;
	int	mouse_right;
} t_input;

typedef struct s_map {
	t_tile **	grid;
	size_t		grid_height;
	size_t		grid_width;
	t_image *	bkg_img;
	size_t		bkg_img_height;
	size_t		bkg_img_width;
	t_itbl *	player1;
	t_itbl *	exit;
	t_itbl **	coins;
	t_itbl **	slimes;
} t_map;

typedef struct s_vars {
	t_mlx_data *	data;
	t_map *			map;
	t_input *		input;
} t_vars;

size_t				ft_printf(const char *str, ...);

void *				ft_memcpy(void *dst, const void *src, size_t n);
char *				ft_strdup(char *src);
void *				ft_memset(void *b, int c, size_t len);
void **				ft_malloc_2d(size_t height, size_t width, size_t pointerSize, size_t elementSize);
int					ft_2d_count_val(char ** map, int width, int height, char target);

t_image *			ft_read_xpm(t_mlx_data* data, char* relative_path);
t_image *			ft_new_image(t_mlx_data* data, int width, int height);
void				ft_fill_image(t_image* img, int color);
int					ft_mlx_put_image_to_win(t_mlx_data* data, t_image* img, int x, int y);
void				ft_image_destory(t_mlx_data * data, t_image * image);

void				ft_mlx_pixel_put(t_image* img, int x, int y, unsigned int color);
t_mlx_data *		ft_mlx_init(int window_width, int window_height, char *window_title);
void				ft_mlx_destory(t_mlx_data * data);
int					ft_add_to_free_arr(t_free_arr * free_arr, void * target);

int					ft_is_valid_map(const char *path);
char **				ft_generate_raw_map(const char* path, size_t *width, size_t *height);
void				ft_map_init_cords(t_map* map, char** raw_map, int width, int height);
t_map *				ft_map_init(const char* path);

t_sprite *			ft_init_sprite(t_image *img, int x, int y, t_vec2 grid_size);
t_sprite **			ft_generate_sprites_array_grid(t_image *image, t_vec2 start, t_vec2 end, t_vec2 grid_size);
t_sprite **			ft_generate_sprites_array_rows(t_image *image, t_vec2 start, t_vec2 end, t_vec2 grid_size);
t_ani_sprite *		ft_init_animated_sprite(t_mlx_data * data, t_sprite** sprites, int length, int frame_interval);
void				ft_mlx_put_sprite(t_image* image, t_sprite* sprite,int x, int y);
void				ft_sprite_destory(t_sprite * sprite);
void				ft_ani_sprite_destory(t_ani_sprite * animated);

void				init_sp_data(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS]);
t_ani_sprite ***	ft_get_bee_ani_sprites(t_mlx_data * data);
t_ani_sprite ***	ft_get_slime_ani_sprites(t_mlx_data * data);
t_ani_sprite ***	ft_get_slime2_ani_sprites(t_mlx_data * data);
t_ani_sprite ***	ft_get_player_ani_sprites(t_mlx_data * data);
t_ani_sprite ***	ft_get_coin_ani_sprites(t_mlx_data * data);

t_itbl *			ft_init_interactable(t_ani_sprite *** sprite_tab);
void				ft_put_interactable_to_img(t_image * base_img, t_itbl * itbl, int x, int y);
void				ft_mlx_put_sprite_reverse(t_image* image, t_sprite* sprite, int img_x, int img_y);
void				ft_itbl_reset_ani(t_itbl * itbl);
void				ft_update_itbl_status(t_itbl * itbl);
void				ft_itbl_destory(t_itbl *itbl);

t_input				ft_init_input(void);
int					ft_on_key_press(int keycode, t_vars * param);
int					ft_on_key_release(int keycode, t_vars * param);
#endif