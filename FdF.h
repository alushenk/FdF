//
// Created by Anton Lushenko on 2/17/17.
//

#ifndef FDF_FDF_H
#define FDF_FDF_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../../LIBFT/libft.h"

#define WINDOW_SIZE_X 900
#define WINDOW_SIZE_Y 600

typedef struct      s_struct
{
    void    *init;
    void    *window;

    int x;
    int y;
}                   t_struct;

typedef struct      s_mas
{
    int cols;
    int rows;
    int **arr;
}                   t_mas;

void    fdf();

/*
** array.c
*/
void    mas_get_size(char *path, t_mas *mas);
void    mas_create(t_mas *mas);
void    mas_fill(char *path, t_mas *mas);

#endif //FDF_FDF_H
