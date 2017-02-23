//
// Created by Anton Lushenko on 2/23/17.
//

#include "FdF.h"

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