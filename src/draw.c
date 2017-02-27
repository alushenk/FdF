//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

static void    write_pixel(int x, int y, int *color, t_struct *mlx)
{
    int a;

    a = ((int)y * mlx->line_size + ((int)x * (mlx->bits_per_pixel / 8)));
    mlx->image_data[a] = color[0];
    mlx->image_data[a + 1] = color[1];
    mlx->image_data[a + 2] = color[2];
}

static int     in_range(int x, int y)
{
    if (x < 0 || y < 0 || x >= WINDOW_SIZE_X || y >= WINDOW_SIZE_Y)
        return (0);
    return (1);
}

void     get_color(int *color, int start, int end, int dist)
{
    color[0] = ((char)start>>(2 * 8)) - ((char)end>>(2 * 8));
    color[1] = ((char)start>>(1 * 8)) - ((char)end>>(1 * 8));
    color[2] = (char)start - (char)end;
    if (dist)
    {
        color[0] /= dist;
        color[1] /= dist;
        color[2] /= dist;
    }
}

static void    draw_line(t_pixel *start, t_pixel *end, t_struct *mlx)
{
    int     move_x;
    int     move_y;
    int     delta_x;
    int     delta_y;

    int     *step_color;
    int     *color;

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

    step_color = (int*)malloc(sizeof(int) * 3);
    color = (int*)malloc(sizeof(int) * 3);
    get_color(step_color, start->color, end->color, (delta_x > delta_y) ? delta_x : delta_y);
    color[0] = (char)start>>(2 * 8);
    color[1] = (char)start>>(1 * 8);
    color[2] = (char)start;

    //if (in_range(end->x, end->y))
    //    write_pixel(end->x, end->y, end->color, mlx);
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
        color[0] += step_color[0];
        color[1] += step_color[1];
        color[2] += step_color[2];
    }
    free(step_color);
    free(color);
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
            if (x->right && x->right->x)
                draw_line(x, x->right, mlx);
            if (x->down && x->down->y)
                draw_line(x, x->down, mlx);
            if (x->right && x->right->down && x->right->down->x && x->right->down-y)
                draw_line(x, x->right->down, mlx);
            x = x->right;
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