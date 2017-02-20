//
// Created by Anton Lushenko on 2/17/17.
//

#ifndef FDF_FDF_H
#define FDF_FDF_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../../LIBFT/libft.h"

#define WINDOW_SIZE_X 900
#define WINDOW_SIZE_Y 600

#define DIST 3
#define ANGLE 0

int g_angle;
int x_center;
int y_center;

typedef struct      s_struct
{
    int cols;
    int rows;
    int **arr;

    void    *init;
    void    *window;
    void    *image;
    char    *image_data;
    int     bits_per_pixel;
    int     line_size;
}                   t_struct;

/*
** array.c
*/
void    mas_get_size(char *path, t_struct *mas);
void    mas_create(t_struct *mas);
void    mas_fill(char *path, t_struct *mas);
/*
** draw.c
*/
void    draw_line(int x0, int y0, int x1, int y1, t_struct *mlx);
void    fdf(t_struct *mlx);

#endif //FDF_FDF_H
