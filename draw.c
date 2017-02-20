//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

void    write_pixel(int x, int y, t_struct *mlx)
{
    int a;

    a = (y * mlx->line_size + (x * (mlx->bits_per_pixel / 8)));
    mlx->image_data[a] = 0;
    mlx->image_data[a + 1] = 0;
    mlx->image_data[a + 2] = 255;
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
    int endian;

    (*mlx)->image = mlx_new_image((*mlx)->init, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    (*mlx)->image_data = mlx_get_data_addr((*mlx)->image, &(*mlx)->bits_per_pixel, &(*mlx)->line_size, &endian);
    draw_line(0, 0, 300, 300, *mlx);
    mlx_put_image_to_window((*mlx)->init, (*mlx)->window, (*mlx)->image, 0, 0);
}