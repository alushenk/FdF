//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

static void    write_pixel(int x, int y, double *color, t_map *mlx)
{
    int a;

    a = ((int)y * mlx->line_size + ((int)x * (mlx->bits_per_pixel / 8)));
    mlx->image_data[a] = (unsigned char)color[2];
    mlx->image_data[a + 1] = (unsigned char)color[1];
    mlx->image_data[a + 2] = (unsigned char)color[0];
}

static int     in_range(int x, int y)
{
    if (x < 0 || y < 0 || x >= WINDOW_SIZE_X || y >= WINDOW_SIZE_Y)
        return (0);
    return (1);
}

void     get_color(double *color, int start, int end, double dist)
{
    color[0] = (((unsigned char)(end>>(2 * 8)) - (unsigned char)(start>>(2 * 8))));
    color[1] = (((unsigned char)(end>>(1 * 8)) - (unsigned char)(start>>(1 * 8))));
    color[2] = (unsigned char)end - (unsigned char)start;
    if (dist)
    {
        color[0] /= dist;
        color[1] /= dist;
        color[2] /= dist;
    }
}

static void    draw_line(t_pixel *start, t_pixel *end, t_map *mlx, double *color, double *color_step)
{
    int     move_x;
    int     move_y;
    int     delta_x;
    int     delta_y;

    int     error;
    int     error2;
    int     x;
    int     y;
    int     x1;
    int     y1;

    x = start->x;
    y = start->y;
    x1 = end->x;
    y1 = end->y;
    move_x = start->x < end->x ? 1 : -1;
    move_y = start->y < end->y ? 1 : -1;
    delta_x = abs(x1 - x);
    delta_y = abs(y1 - y);
    error = delta_x - delta_y;

    color[0] = (unsigned char)(start->color>>(2 * 8));
    color[1] = (unsigned char)(start->color>>(1 * 8));
    color[2] = (unsigned char)start->color;
    get_color(color_step, start->color, end->color, sqrt(pow((end->x - start->x), 2) + pow((end->y - start->y), 2)));

    while (x != x1 || y != y1)
    {
        if (in_range(x, y))
            write_pixel(x, y, color, mlx);
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
        color[0] += color_step[0];
        color[1] += color_step[1];
        color[2] += color_step[2];
    }
    if (in_range(end->x, end->y))
        write_pixel(end->x, end->y, color, mlx);
}

static void    draw_map(t_map *mlx)
{
    t_pixel *y;
    t_pixel *x;
    double     *color_step;
    double     *color;

    color = (double*)malloc(sizeof(double) * 3);
    color_step = (double*)malloc(sizeof(double) * 3);
    y = mlx->pixel;
    while (y->down)
    {
        x = y;
        while (x->right)
        {
            if (x->right && x->right->x)
                draw_line(x, x->right, mlx, color, color_step);
            if (x->down && x->down->y)
                draw_line(x, x->down, mlx, color, color_step);
            if (x->right && x->right->down && x->right->down->x && x->right->down-y)
                draw_line(x, x->right->down, mlx, color, color_step);
            x = x->right;
        }
        y = y->down;
    }
    free(color);
    free(color_step);
}

void    draw(t_map *mlx)
{
    if (mlx->image)
        mlx_destroy_image(mlx->init, mlx->image);
    mlx->image = mlx_new_image(mlx->init, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    mlx->image_data = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel, &mlx->line_size, &mlx->endian);
    prepare_matrix(mlx);
    draw_map(mlx);
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->image, 0, 0);
}