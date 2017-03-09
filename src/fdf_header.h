/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:22:12 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 19:22:14 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_HEADER_H
# define FDF_FDF_HEADER_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../externals/get_next_line/get_next_line.h"
# include "../externals/get_next_line/libft/libft.h"

# define U_CHAR unsigned char

# define WIN_SIZE_X 2000
# define WIN_SIZE_Y 1250

# define RAD (3.14 / 180)
# define STEP_MOVE 20
# define STEP_ROTATE 2
# define STEP_ZOOM_INCREASE 1.5
# define STEP_ZOOM_DECREASE 0.5

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_SCALE_INCREASE 69
# define KEY_SCALE_DECREASE 78
# define KEY_EXIT 53

# define KEY_ROTATE_X_RIGHT 91
# define KEY_ROTATE_X_LEFT 84
# define KEY_ROTATE_Y_RIGHT 88
# define KEY_ROTATE_Y_LEFT 86
# define KEY_ROTATE_Z_RIGHT 85
# define KEY_ROTATE_Z_LEFT 83

typedef struct		s_pixel
{
	double			x;
	double			y;
	double			z;
	int				color;
	struct s_pixel	*right;
	struct s_pixel	*down;
}					t_pixel;

typedef struct		s_map
{
	int				cols;
	int				rows;
	double			center_x;
	double			center_y;
	double			center_z;
	t_pixel			*pixel;
	void			*init;
	void			*win;
	void			*img;
	char			*img_d;
	int				e;
	int				bpp;
	int				l_size;
}					t_map;

typedef struct		s_limits
{
	double			max_x;
	double			max_y;
	double			max_z;
	double			min_x;
	double			min_y;
	double			min_z;
}					t_limits;

typedef struct		s_cent
{
	double			old_x;
	double			old_y;
	double			old_z;
}					t_cent;

typedef struct		s_bresenham
{
	int				move_x;
	int				move_y;
	int				delta_x;
	int				delta_y;
	int				error;
	int				error2;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	double			dist;
}					t_bresenham;

typedef struct		s_color
{
	double			*color_step;
	double			*color;
}					t_color;
/*
** array.c
*/
void				parse_file(t_map *mlx, int fd);
/*
** draw.c
*/
void				draw(t_map *mlx);
/*
** draw0.c
*/
void				write_pixel(int x, int y, double *color, t_map *mlx);
int					in_range(int x, int y);
void				get_color(double *color, int start, int end, double dist);
void				bresen_init(t_bresenham *b, t_pixel *start, t_pixel *end);
void				color_init(double **color, t_pixel *start);
/*
** events.c
*/
int					key_hook(int key, t_map *mlx);
/*
** events_get.c
*/
void				get_event_ab(int *a, int *b, int comb);
void				g_cent(t_cent *o, double *cen_a, double *cen_b, int comb);
/*
** matrix.c
*/
void				prepare_matrix(t_map *mlx);
void				move_matrix(t_pixel *pixel, double move, int combination);
void				zoom_matrix(t_pixel *pixel, double multiplier);
/*
** centrate_matrix.c
*/
void				find_centre(t_map *mlx);
/*
** rotate.c
*/
void				rotate(t_pixel *pixel, double angle, int combination);
/*
** error.c
*/
void				error_parse(void);
void				error_open(void);

#endif
