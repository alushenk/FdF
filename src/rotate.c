//
// Created by Anton Lushenko on 2/25/17.
//

#include "FdF.h"

void    rotate(t_pixel *pixel, double angle, int combination)
{
    double a;
    double b;
    t_pixel *x;
    t_pixel *y;

    y = pixel;
    while (y->down)
    {
        x = y;
        while (x->right)
        {
            if (combination == 0)
            {
                a = x->x;
                b = x->y;
            }
            if (combination == 1)
            {
                a = x->x;
                b = x->z;
            }
            else if (combination == 2)
            {
                a = x->y;
                b = x->z;
            }
            a = (a * cos(angle * RAD)) - (b * sin(angle * RAD));
            b = (a * sin(angle * RAD)) + (b * cos(angle * RAD));

            if (combination == 0)
            {
                x->x = a;
                x->y = b;
            }
            if (combination == 1)
            {
                x->x = a;
                x->z = b;
            }
            else if (combination == 2)
            {
                x->y = a;
                x->z = b;
            }
            x = x->right;
        }
        y = y->down;
    }
}
