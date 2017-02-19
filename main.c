//
// Created by Anton Lushenko on 2/17/17.
//

#include "FdF.h"

void    print_mas(t_mas *mas)
{
    int i;
    int j;

    i = 0;
    while (i < mas->rows)
    {
        j = 0;
        while (j < mas->cols)
        {
            printf("%-3d", mas->arr[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

void    parse_file(char *path)
{
    t_mas mas;

    mas_get_size(path, &mas);
    mas_create(&mas);
    mas_fill(path, &mas);

    print_mas(&mas);

    fdf_image();

}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        parse_file(argv[1]);
    }
    else
        printf("arguments needed");
    return (0);

}