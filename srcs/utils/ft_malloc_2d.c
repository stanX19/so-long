#include "so_long.h"

void** ft_malloc_2d(size_t height, size_t width, size_t pointerSize, size_t elementSize) {
    size_t rowSize = elementSize * height;
    size_t totalRowSize = rowSize + pointerSize;

    void** array = (void**)malloc(width * totalRowSize);

    if (array == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < width; i++) {
        array[i] = (void*)((char*)array + i * totalRowSize + pointerSize);
    }

    return array;
}