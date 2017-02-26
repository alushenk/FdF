//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

t_pixel     *new_pixel(int x, int y, int z, int color)
{
    t_pixel *result;

    result = (t_pixel*)malloc(sizeof(t_pixel));
    result->x = x;
    result->y = y;
    result->z = z;
    result->color = color;
    result->right = NULL;
    result->down = NULL;
}

int hex_to_int(char **hex)
{
    size_t result;
    char byte;

    result = 0;
    while (**hex != ' ' && **hex)
    {
        byte = **hex;
        (*hex)++;
        if (ft_isdigit(byte))
            byte -= '0';
        else if (ft_islower(byte))
            byte = byte - 'a' + 10;
        else if (ft_isupper(byte))
            byte = byte - 'A' + 10;
        result = (result << 4) | (byte & 0xF);
    }
    return ((int)result);
}

static int     get_row(char *str, t_pixel *pixel, int y)
{
    int result;

    result = 0;
    if (str == NULL)
        return (0);
    while(*str)
    {
        if (pixel == NULL)
            pixel = (t_pixel*)malloc(sizeof(t_pixel));
        else
        {
            pixel->right = (t_pixel*)malloc(sizeof(t_pixel));
            pixel = pixel->right;
        }
        while (*str == ' ')
            str++;
        pixel->x = result;
        pixel->y = y;
        if (ft_isdigit(*str))
        {
            result++;
            pixel->z = atoi_skip(&str);
        }
        if (ft_strncmp(str, ",0x", 3) == 0)
        {
            str += 3;
            pixel->color = hex_to_int(&str);
        }
        pixel->right = NULL;
    }
    return (result);
}

static void    parse_file(char *path, t_struct *mlx)
{
    int     fd;
    char    *line;
    t_pixel *pixel;
    int     cols;

    mlx->pixel = (t_pixel*)malloc(sizeof(t_pixel));
    pixel = mlx->pixel;
    fd = open(path, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        cols = get_row(line, pixel, mlx->rows);
        if (mlx->cols == 0)
            mlx->cols = cols;
        if (mlx->cols != cols)
        {
            printf("error");
            exit(0);
        }
        free(line);
        mlx->rows++;
        pixel->down = (t_pixel*)malloc(sizeof(t_pixel));
        pixel = pixel->down;
    }
    close(fd);
}