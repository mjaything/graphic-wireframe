#include "fdf.h"
#include <stdlib.h>

void                push(t_matrix_element **matrix_elements_stack,
                            t_matrix_element *new_element)
{
    if (matrix_elements_stack)
    {
        if (new_element)
            new_element->next = *matrix_elements_stack;
        *matrix_elements_stack = new_element;
    }
}

t_matrix_element    *pop(t_matrix_element **matrix_elements_stack)
{
    t_matrix_element    *top;

    top = NULL;
    if (matrix_elements_stack && *matrix_elements_stack)
    {
        top = *matrix_elements_stack;
        *matrix_elements_stack = (*matrix_elements_stack)->next;
    }
    return (top);
}

void                transform_to_array(t_matrix_element **matrix_element_stack,
                                        t_map *map)
{
    t_matrix_element    *matrix_element;
    size_t              arr_size;
    ssize_t             i;

    arr_size = map->width * map->height * sizeof(int);
    if (!(map->matrix_element_arr = (int *)ft_memalloc(arr_size)))
        terminate()
    if (!(map->color_arr = (int *)ft_memalloc(arr_size)))
        terminate()
    i = map->width * map->height - 1;
    while ((matrix_element = pop(matrix_element_stack)) && i >= 0)
    {
        map->matrix_element_arr[i] = matrix_element->z;
        map->color_arr[i] = matrix_element->color;
        if (matrix_element->z > map->z_max)
            map->z_max = matrix_element->z;
        if (matrix_element->z < map->z_min)
            map->z_min = matrix_element->z;
        i--;
        free(matrix_element);
    }
    map->z_range = map->z_max - map->z_min;
}