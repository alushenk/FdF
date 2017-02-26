//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

static void    write_pixel(double x, double y, int color, t_struct *mlx)
{
    int a;

    a = ((int)y * mlx->line_size + ((int)x * (mlx->bits_per_pixel / 8)));
    mlx->image_data[a] = 100;
    mlx->image_data[a + 1] = 100;
    mlx->image_data[a + 2] = 0;
}

static int     in_range(int x, int y)
{
    if (x < 0 || y < 0 || x >= WINDOW_SIZE_X || y >= WINDOW_SIZE_Y)
        return (0);
    return (1);
}

static void    draw_line(t_pixel *start, t_pixel *end, t_struct *mlx)
{
    int     move_x;
    int     move_y;
    int     delta_x;
    int     delta_y;
    int     error;
    int     error2;
    int     x;
    int     y;

    move_x = start->x < end->x ? 1 : -1;
    move_y = start->y < end->y ? 1 : -1;
    delta_x = abs(end->x - start->y);
    delta_y = abs(end->y - start->y);
    error = delta_x - delta_y;
    x = start->x;
    y = start->y;
    if (in_range(end->x, end->y))
        write_pixel(end->x, end->y, end->color, mlx);
    while (x != end->x|| y != end->y)
    {
        if (in_range(x, y))
            write_pixel(x, y, end->color, mlx);
        error2 = error * 2;
        if (error2 > -delta_y)
        {
            error -= delta_y;
            x += move_x;
        }
        if (error2 < delta_x)
        {
            error += delta_x;
            y += move_y;
        }
    }
}

static void    draw_map(t_struct *mlx)
{
    t_pixel *y;
    t_pixel *x;

    y = mlx->pixel;
    while (y->down)
    {
        x = y;
        while (x->right)
        {
            if (x->right->x)
                draw_line(x, x->right, mlx);
            if (x->down->y)
                draw_line(x, x->down, mlx);
            //if (x + 1 < mlx->cols && y + 1 < mlx->rows)
            //    draw_line(mlx->arr_x[y][x], mlx->arr_y[y][x], mlx->arr_x[y][x + 1], mlx->arr_y[y + 1][x], mlx);
            x++;
        }
        y = y->down;
    }
}

void    draw(t_struct *mlx)
{
    if (mlx->image)
        mlx_destroy_image(mlx->init, mlx->image);
    mlx->image = mlx_new_image(mlx->init, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    mlx->image_data = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel, &mlx->line_size, &mlx->endian);
    prepare_matrix(mlx);
    draw_map(mlx);
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->image, 0, 0);
}