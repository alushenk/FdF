//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

static void    write_pixel(int x, int y, t_struct *mlx)
{
    int a;

    a = (y * mlx->line_size + (x * (mlx->bits_per_pixel / 8)));
    mlx->image_data[a] = 255;
    mlx->image_data[a + 1] = 0;
    mlx->image_data[a + 2] = 0;
}

static int     in_range(int x, int y, int max_x, int max_y)
{
    if (x < 0 || y < 0 || x >= WINDOW_SIZE_X || y >= WINDOW_SIZE_Y || x > (max_x * 30) || y > (max_y * 30))
        return (0);
    return (1);
}

static void    draw_line(int x0, int y0, int x1, int y1, t_struct *mlx)
{
    int     move_x;
    int     move_y;
    int     delta_x;
    int     delta_y;
    int     error;

    int     error2;

    move_x = x0 < x1 ? 1 : -1;
    move_y = y0 < y1 ? 1 : -1;
    delta_x = abs(x1 - x0);
    delta_y = abs(y1 - y0);
    error = delta_x - delta_y;

    if (in_range(x1, y1, mlx->cols, mlx->rows))
        write_pixel(x1, y1, mlx);
    while (x0 != x1 || y0 != y1)
    {
        if (in_range(x0, y0, mlx->cols, mlx->rows))
            write_pixel(x0, y0, mlx);
        error2 = error * 2;
        if (error2 > -delta_y)
        {
            error -= delta_y;
            x0 += move_x;
        }
        if (error2 < delta_x)
        {
            error += delta_x;
            y0 += move_y;
        }
    }
}

static void    draw_map(t_struct *mlx)
{
    int x;
    int y;
    int x1;
    int y1;
    int x2;
    int y2;

    mlx->cols--;
    mlx->rows--;
    y = 0;
    while (y <= mlx->rows)
    {
        x = 0;
        while (x <= mlx->cols)
        {
            x1 = x * 30;
            y1 = y  * 30;
            x2 = (x + 1) * 30;
            y2 = (y + 1) * 30;
            draw_line(x1, y1, x2, y1, mlx);
            draw_line(x1, y1, x1, y2, mlx);
            x++;
        }
        y++;
    }
}

void    draw(t_struct *mlx)
{
    if (mlx->image)
        mlx_destroy_image(mlx->init, mlx->image);
    mlx->image = mlx_new_image(mlx->init, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    mlx->image_data = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel, &mlx->line_size, &mlx->endian);

    //центровку и сайз надо делать где-то снаружи, один раз
    prepare_matrix(mlx);
    draw_map(mlx);
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->image, 0, 0);
}