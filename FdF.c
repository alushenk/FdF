//
// Created by Anton Lushenko on 2/17/17.
//

#include "FdF.h"

void    struct_init(t_struct **mlx)
{
    if (*mlx == NULL)
        *mlx = (t_struct*)malloc(sizeof(t_struct));
    (*mlx)->x = 0;
    (*mlx)->y = 0;
    (*mlx)->init = NULL;
    (*mlx)->window = NULL;
    (*mlx)->image = NULL;
}

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

int    close_window(int key, t_struct *mlx)
{
    if (key == 0)
    {
        //mlx_destroy_window(init, window);
        exit(0);
    }
    if (key == 124)
    {
        mlx_clear_window (mlx->init, mlx->window);
        mlx->x += 10;
        put_rect(mlx->x, mlx->y, mlx->init, mlx->window);
    }
    if (key == 123)
    {
        mlx_clear_window (mlx->init, mlx->window);
        mlx->x -= 10;
        put_rect(mlx->x, mlx->y, mlx->init, mlx->window);
    }
    if (key == 125)
    {
        mlx_clear_window (mlx->init, mlx->window);
        mlx->y += 10;
        put_rect(mlx->x, mlx->y, mlx->init, mlx->window);
    }
    if (key == 126)
    {
        mlx_clear_window (mlx->init, mlx->window);
        mlx->y -= 10;
        put_rect(mlx->x, mlx->y, mlx->init, mlx->window);
    }
    return (0);
}

int     print_mouse(int key, int x, int y, t_struct *mlx)
{
    printf("key = %d\t x = %d\t y = %d\n", key, x, y);
    return (0);
}

void    fdf()
{
    t_struct *mlx;

    mlx = NULL;
    struct_init(&mlx);

    mlx->init = mlx_init();
    if (mlx->init == NULL)
        printf("error");
    mlx->window = mlx_new_window(mlx->init, WINDOW_SIZE_X, WINDOW_SIZE_Y, "FdF");
    if (mlx->window == NULL)
        printf("error");
    //put_rect(mlx->x, mlx->y, mlx->init, mlx->window);
    draw_line(10, 10, 500, 500, mlx);

    mlx_key_hook(mlx->window, close_window, mlx);
    //mlx_mouse_hook(mlx->window, print_mouse, mlx);
    mlx_loop(mlx->init);
}

void    fdf_image()
{
    t_struct *mlx;

    mlx = NULL;
    struct_init(&mlx);

    mlx->init = mlx_init();
    if (mlx->init == NULL)
        printf("error");
    mlx->window = mlx_new_window(mlx->init, WINDOW_SIZE_X, WINDOW_SIZE_Y, "FdF");
    if (mlx->window == NULL)
        printf("error");
    //put_rect(mlx->x, mlx->y, mlx->init, mlx->window);
    draw(&mlx);

    mlx_key_hook(mlx->window, close_window, mlx);
    //mlx_mouse_hook(mlx->window, print_mouse, mlx);
    mlx_loop(mlx->init);
}