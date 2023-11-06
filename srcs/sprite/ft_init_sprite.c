#include "so_long.h"

sprite_t ft_sprite_init(void *mlx_ptr, char *path, size_t x, size_t y, size_t tile_width, size_t tile_height) {
    sprite_t new_sprite;

    // Load the image using mlx_xpm_file_to_image (assuming the image is in PNG format)
    new_sprite.img = mlx_xpm_file_to_image(mlx_ptr, path, &new_sprite.width, &new_sprite.height);

    if (new_sprite.img == NULL) {
        // Handle error, e.g., by setting width and height to 0 or returning an error code.
        new_sprite.width = 0;
        new_sprite.height = 0;
        return new_sprite;
    }

    // Calculate the width and height of the cropped portion
    size_t cropped_width = tile_width;
    size_t cropped_height = tile_height;

    // Get the pixel data for the image
    new_sprite.addr = (char *)mlx_get_data_addr(new_sprite.img, &new_sprite.width, &new_sprite.height, 0);

    // Calculate the start index for the cropped portion
    size_t start_index = (y * new_sprite.width + x) * 4; // Assuming 32-bit RGBA image (4 bytes per pixel)

    // Update width and height accordingly
    new_sprite.width = cropped_width;
    new_sprite.height = cropped_height;

    // Update data to point to the start of the cropped portion
    new_sprite.addr += start_index;

    return new_sprite;
}