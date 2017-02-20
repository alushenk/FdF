//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

void    struct_init(t_struct **mlx)
{
    if (*mlx == NULL)
        *mlx = (t_struct*)malloc(sizeof(t_struct));
    (*mlx)->init = NULL;
    (*mlx)->window = NULL;
    (*mlx)->image = NULL;
}

void    write_pixel(int x, int y, t_struct *mlx)
{
    int a;

    a = (y * mlx->line_size + (x * (mlx->bits_per_pixel / 8)));
    mlx->image_data[a] = 255;
    mlx->image_data[a + 1] = 0;
    mlx->image_data[a + 2] = 0;
}

int    key_hook(int key, t_struct *mlx)
{
    if (key == 0)
    {
        //mlx_destroy_window(mlx->init, mlx->window);
        exit(0);
    }
    if (key == 86)
    {
    }
    if (key == 88)
    {
        //g_angle++;
        //fdf(mlx);
        //end program, free shit
        //launch fdf(), but with new image, not window. with new angle values
    }
    return (0);
}

int     in_range(int x, int y, int max_x, int max_y)
{
    if (x < 0 || y < 0 || x >= WINDOW_SIZE_X || y >= WINDOW_SIZE_Y || x > ((max_x + x_center) * DIST) || y > ((max_y + y_center) * DIST))
        return (0);
    return (1);
}

void    draw_line(int x0, int y0, int x1, int y1, t_struct *mlx)
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

void    draw_map(t_struct *mlx)
{
    int x;
    int y;
    int x1;
    int y1;
    int x2;
    int y2;

    x_center = WINDOW_SIZE_X / 2;
    y_center = WINDOW_SIZE_Y / 2;

    y = y_center;
    while (y < ((mlx->rows + y_center) * DIST))
    {
        x = x_center;
        while (x < ((mlx->cols + x_center) * DIST))
        {
            //x1 = (x * DIST) * cos(g_angle) - (y * DIST) * sin(g_angle);
            //y1 = (x * DIST) * cos(g_angle) + (y * DIST) * cos(g_angle);
            //x2 = ((x + 1) * DIST) * cos(g_angle) - (y * DIST) * sin(g_angle);
            //y2 = (x * DIST) * cos(g_angle) + ((y + 1) * DIST)  * cos(g_angle);
            x1 = (x + x_center) * DIST;
            y1 = (y + y_center) * DIST;
            x2 = (x + 1 + x_center) * DIST;
            y2 = (y + 1 + y_center) * DIST;
            draw_line(x1, y1, x2, y1, mlx);
            draw_line(x1, y1, x1, y2, mlx);
            x++;
        }
        y++;
    }
    //draw_line(0, 0, 300, 300, mlx);
}

void    fdf(t_struct *mlx)
{
    int endian;

    struct_init(&mlx);
    mlx->init = mlx_init();
    mlx->window = mlx_new_window(mlx->init, WINDOW_SIZE_X, WINDOW_SIZE_Y, "FdF");

    mlx->image = mlx_new_image(mlx->init, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    mlx->image_data = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel, &mlx->line_size, &endian);

    draw_map(mlx);

    mlx_put_image_to_window(mlx->init, mlx->window, mlx->image, 0, 0);
    mlx_key_hook(mlx->window, key_hook, mlx);
    //mlx_mouse_hook(mlx->window, print_mouse, mlx);
    mlx_loop(mlx->init);
}