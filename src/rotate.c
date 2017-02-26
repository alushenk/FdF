//
// Created by Anton Lushenko on 2/25/17.
//

#include "FdF.h"

void    rotate_x(t_pixel *pixel, int angle)
{
    double y;
    double z;
    t_pixel *col;
    t_pixel *row;

    row = pixel;
    while (row->down)
    {
        col = row;
        while (col->right)
        {
            y = col->y;
            z = col->z;
            col->y = (y * cos(angle * RAD)) - (z * sin(angle * RAD));
            col->z = (y * sin(angle * RAD)) + (z * cos(angle * RAD));
            col = col->right;
        }
        row = row->down;
    }
}

void    rotate_y(t_pixel *pixel, int angle)
{
    double x;
    double z;
    t_pixel *col;
    t_pixel *row;

    row = pixel;
    while (row->down)
    {
        col = row;
        while (col->right)
        {
            x = col->x;
            z = col->z;
            col->x = (x * cos(angle * RAD)) - (z * sin(angle * RAD));
            col->z = (x * sin(angle * RAD)) + (z * cos(angle * RAD));
            col = col->right;
        }
        row = row->down;
    }
}

void    rotate_z(t_pixel *pixel, int angle)
{
    double x;
    double y;
    t_pixel *col;
    t_pixel *row;

    row = pixel;
    while (row->down)
    {
        col = row;
        while (col->right)
        {
            x = col->x;
            y = col->y;
            col->x = (x * cos(angle * RAD)) - (y * sin(angle * RAD));
            col->y = (x * sin(angle * RAD)) + (y * cos(angle * RAD));
            col = col->right;
        }
        row = row->down;
    }
}
