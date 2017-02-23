//
// Created by Anton Lushenko on 2/23/17.
//

#include "FdF.h"

int    key_hook(int key, t_struct *mlx)
{
    if (key == KEY_SCALE_INCREASE)
    {
        mlx->zoom *= 1.5;
        draw(mlx);
    }
    else if (key == KEY_SCALE_DECREASE)
    {
        mlx->zoom *= 0.5;
        draw(mlx);
    }
    else if (key == KEY_RIGHT)
    {
    }
    else if (key == KEY_LEFT)
    {
    }
    else if (key == KEY_UP)
    {
    }
    else if (key == KEY_DOWN)
    {
    }
    else if (key == KEY_EXIT)
    {
        exit(0);
    }
    else if (key == KEY_ROTATE_Z_RIGHT)
    {
    }
    else if (key == KEY_ROTATE_Z_LEFT)
    {
    }
    else if (key == 88)
    {
        //g_angle++;
        //fdf(mlx);
        //end program, free shit
        //launch fdf(), but with new image, not window. with new angle values
    }
    return (0);
}