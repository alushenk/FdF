//
// Created by Anton Lushenko on 2/17/17.
//

#include "FdF.h"

void    print_mlx(double **arr, int rows, int cols)
{
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            printf("%-15f", arr[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

static void    struct_init(t_struct **mlx)
{
    if (*mlx == NULL)
        *mlx = (t_struct*)malloc(sizeof(t_struct));
    (*mlx)->init = NULL;
    (*mlx)->window = NULL;
    (*mlx)->image = NULL;
    (*mlx)->center_x = 0;
    (*mlx)->center_y = 0;
    (*mlx)->cols = 0;
    (*mlx)->rows = 0;

}

int exit_button()
{
    exit(0);
}

int main(int argc, char **argv)
{
    t_struct *mlx;

    if (argc == 2)
    {
        struct_init(&mlx);
        parse_file(argv[1], mlx);
        mlx->init = mlx_init();
        mlx->window = mlx_new_window(mlx->init, WINDOW_SIZE_X, WINDOW_SIZE_Y, "FdF");

        /*
        print_mlx(mlx->arr_x, mlx->rows, mlx->cols);
        printf("\n");
        print_mlx(mlx->arr_y, mlx->rows, mlx->cols);
        printf("\n");
        print_mlx(mlx->arr_z, mlx->rows, mlx->cols);
        printf("\n");
        */

        draw(mlx);

        mlx_hook(mlx->window, 2, 5, key_hook, mlx);
        mlx_hook(mlx->window, 17, 0L, exit_button, 0);
        //mlx_mouse_hook(mlx->window, print_mouse, mlx);
        mlx_loop(mlx->init);
    }
    else
        printf("arguments needed");
    return (0);

}