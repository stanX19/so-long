SRCDIR	= srcs
# SPRITE	= sprite
# IMAGE	= image
# MAP		= map
# UTILS	= utils
# INTER	= interactable
# MLXUTILS	= mlx_utils
SRCS		= $(wildcard ./$(SRCDIR)/*/*.c)
# SRCS	=	$(addsuffix .c, \
# 		$(addprefix $(SRCDIR)/ft_, \
# 			) \
# 		$(addprefix $(SRCDIR)/$(IMAGE)/ft_, \
# 			add_img_to_arr\
# 			fill_image image_destory\
# 			mlx_put_image_to_win\
# 			new_image read_xpm)\
# 		$(addprefix $(SRCDIR)/$(INTER)/ft_, \
# 			get_bee_ani_sprites\
# 			init_interactable\
# 			put_interactable_to_img\
# 			init_sp_data)\
# 		$(addprefix $(SRCDIR)/$(MAP)/ft_, \
# 			generate_raw_map\
# 			map_init_cords\
# 			initialize_map_sprites\
# 			map_init\
# 			is_valid_map)\
# 		$(addprefix $(SRCDIR)/$(MLXUTILS)/ft_, \
# 			mlx_init\
# 			mlx_pixel_put\
# 			mlx_destory)\
# 		$(addprefix $(SRCDIR)/$(UTILS)/ft_, \
# 			memcpy\
# 			strdup\
# 			malloc_2d)\
# 		$(addprefix $(SRCDIR)/$(SPRITE)/ft_, \
# 			generate_sprites_array\
# 			init_animated_sprite\
# 			init_sprite mlx_put_sprite\
# 			sprite_destory)\
# 			)

HEADER_DIR		= headers
SO_LONG_H		= $(HEADER_DIR)/so_long.h
ASSETS_PATH_H	= $(HEADER_DIR)/assets_path.h
COLORS_H		= $(HEADER_DIR)/trgb_colors.h
CONFIG_H		= $(HEADER_DIR)/configs.h
HEADERS			= $(SO_LONG_H) $(ASSETS_PATH_H) $(COLORS_H) $(CONFIG_H)
OBJDIR			= objs
OBJDIRS			= $(sort $(dir $(OBJS)))
OBJS			= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g3
RM				= rm -rf
TESTDIR			= so_long_tester
TESTGIT			= https://github.com/augustobecker/so_long_tester.git

PRINTF_DIR		= ft_printf
PRINTF_LIB		= $(PRINTF_DIR)/libftprintf.a

MLX_LINUX		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS		= -Lmlx_macos -lmlx -framework OpenGL -framework AppKit
NAME			= so_long

IFLAGS			= -I. -I$(HEADER_DIR) #-Imlx
LINKERS			= $(PRINTF_LIB) $(MLX_MACOS)

MAIN			= main.c
ARGV			= assets/map/big.ber # assets/map/map0.ber assets/map/map1.ber assets/map/map2.ber assets/map/map3.ber assets/map/map4.ber assets/map/map5.ber

UP				= \033[1A
FLUSH			= \033[2K

run: all
	./so_long $(ARGV)
all: $(NAME)

$(NAME): $(MAIN) $(OBJS) $(PRINTF_LIB) $(SO_LONG_H)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) $(IFLAGS) $(LINKERS) -o $(NAME)
$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIRS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"
$(PRINTF_LIB):
	@make --directory=$(PRINTF_DIR) all
clean:
	@$(RM) $(OBJS)
fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) $(OBJDIRS)
	@$(RM) ./a.out
	@make --directory=$(PRINTF_DIR) fclean
re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make && make fclean
xpm:
	find . -type f -name "*.xpm" -exec $(RM) {} \;
	mogrify -format xpm ./assets/*/*/*.png
	@make path_h
path_h:
	@echo "#ifndef ASSETS_PATH_H" > $(ASSETS_PATH_H)
	@echo "# define ASSETS_PATH_H" >> $(ASSETS_PATH_H)
	@find assets/ -type f -name '*.xpm' -exec sh -c 'echo "# define PATH_$$(echo "{}" | tr "/" "_" | awk "{gsub(/.xpm$$/, \"\", \$$0); print toupper(\$$0)}" | sed "s/ASSETS_SPRITES_//") \"{}\"" >> $(ASSETS_PATH_H)' \;
	@echo "# define ALL_PATHS (char*[])\\" >> $(ASSETS_PATH_H)
	@echo "{\\" >> $(ASSETS_PATH_H)
	@find assets/ -type f -name '*.xpm' -exec sh -c 'echo "	PATH_$$(echo "{}" | tr "/" "_" | awk "{gsub(/.xpm$$/, \"\", \$$0); print toupper(\$$0)}" | sed "s/ASSETS_SPRITES_//"),\\" >> $(ASSETS_PATH_H)' \;
	@echo "}" >> $(ASSETS_PATH_H)
	@echo "# define ALL_PATH_LEN (sizeof(ALL_PATHS) / sizeof(char*))" >> $(ASSETS_PATH_H)
	@echo "#endif" >> $(ASSETS_PATH_H)
	cat $(ASSETS_PATH_H)
$(TESTDIR):
	git clone $(TESTGIT)
.PHONY:			all clean fclean re .c.o xpm
