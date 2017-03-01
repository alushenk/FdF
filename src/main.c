/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:28:56 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 17:28:58 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	struct_init(t_map **mlx)
{
	if (*mlx == NULL)
	{
		*mlx = (t_map *)malloc(sizeof(t_map));
	}
	(*mlx)->init = NULL;
	(*mlx)->win = NULL;
	(*mlx)->img = NULL;
	(*mlx)->center_x = 0;
	(*mlx)->center_y = 0;
	(*mlx)->center_z = 0;
	(*mlx)->cols = 0;
	(*mlx)->rows = 0;
}

int			exit_button(void)
{
	exit(0);
}

int			main(int argc, char **argv)
{
	t_map	*mlx;
	int		fd;

	if (argc == 2)
	{
		struct_init(&mlx);
		fd = open(argv[1], O_RDONLY);
		parse_file(mlx, fd);
		close(fd);
		mlx->init = mlx_init();
		mlx->win = mlx_new_window(mlx->init, WIN_SIZE_X, WIN_SIZE_Y, argv[1]);
		draw(mlx);
		mlx_hook(mlx->win, 2, 5, key_hook, mlx);
		mlx_hook(mlx->win, 17, 0L, exit_button, 0);
		mlx_loop(mlx->init);
	}
	else
	{
		printf("arguments needed");
	}
	return (0);
}
