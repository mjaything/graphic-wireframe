#include "fdf.h"
#include <stdlib.h>

void    			push(t_matrix_element **matrix_elements_stack, t_matrix_element *new_element)
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