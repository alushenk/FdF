//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

void    write_pixel(int x, int y, t_struct *mlx)
{
    int a;

    a = (y * (mlx->size_line >> 2) + x) << 2;
    mlx->image[a] = 255;
    mlx->image[a + 1] = 0;
    mlx->image[a + 2] = 0;
}

void    draw_line(int x0, int y0, int x1, int y1, t_struct *mlx)
{
    int     move_x;
    int     move_y;
    int     delta_x;
    int     delta_y;
    int     error;

    move_x = x0 < x1 ? 1 : -1;
    move_y = y0 < y1 ? 1 : -1;
    delta_x = abs(x1 - x0);
    delta_y = abs(y1 - y0);
    error = delta_x + delta_y;

    write_pixel(x1, y1, mlx);
    while (x0 != x1 && y0 != y1)
    {
        write_pixel(x0, y0, mlx);
        if (error >= delta_y)
        {
            error -= delta_y;
            x0 += move_x;
        }
        if (error <= delta_x)
        {
            error += delta_x;
            y0 += move_y;
        }
    }
}

void    draw(t_struct **mlx)
{
    int size_line;
    int bits_per_pixel;
    int endian;

    (*mlx)->image = mlx_new_image((*mlx)->init, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    (*mlx)->image_data = mlx_get_data_addr((*mlx)->image, &bits_per_pixel, &(*mlx)->size_line, &endian);
    draw_line(10, 10, 500, 500, *mlx);
    mlx_put_image_to_window((*mlx)->init, (*mlx)->window, (*mlx)->image, 100, 100);
}



/*
    int     move_x;
    int     move_y;
    int     delta_x;
    int     delta_y;
    int     error;
    int     err;

    move_x = x0 < x1 ? 1 : -1;
    move_y = y0 < y1 ? 1 : -1;
    delta_x = abs(x1 - x0);
    delta_y = -abs(y1 - y0);
    error = delta_x + delta_y;

    while (x0 != x1 && y0 != y1)
    {
        mlx_pixel_put(mlx->init, mlx->window, x0, y0, 0x4EEE94);
        err = error * 2;
        if (err >= delta_y)
        {
            error += delta_y;
            x0 += move_x;
        }
        if (err <= delta_x)
        {
            error += delta_x;
            y0 += move_y;
        }
    }
 */