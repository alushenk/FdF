//
// Created by Anton Lushenko on 2/17/17.
//

#include "FdF.h"



void    put_rect(int x, int y, void *init, void *window)
{
    int i;
    int j;

    i = y;
    while (i < y + 200)
    {
        j = x;
        while (j < x + 200)
        {
            mlx_pixel_put(init, window, j, i, i + j);
            j++;
        }
        i++;
    }
}

int     print_mouse(int key, int x, int y, t_struct *mlx)
{
    printf("key = %d\t x = %d\t y = %d\n", key, x, y);
    return (0);
}