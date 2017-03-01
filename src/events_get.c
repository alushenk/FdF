/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:08:13 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 19:08:15 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void		get_event_ab(int *a, int *b, int comb)
{
	if (comb == 0)
	{
		*a = 3;
		*b = 4;
	}
	else if (comb == 1)
	{
		*a = 3;
		*b = 5;
	}
	else if (comb == 2)
	{
		*a = 4;
		*b = 5;
	}
	else
	{
		ft_putstr("error");
		*a = 0;
		*b = 0;
	}
}

void		get_cent(t_cent *o, double *cen_a, double *cen_b, int comb)
{
	if (comb == 0)
	{
		*cen_a = o->old_x;
		*cen_b = o->old_y;
	}
	else if (comb == 1)
	{
		*cen_a = o->old_x;
		*cen_b = o->old_z;
	}
	else if (comb == 2)
	{
		*cen_a = o->old_y;
		*cen_b = o->old_z;
	}
	else
	{
		ft_putstr("error");
		*cen_a = 0;
		*cen_b = 0;
	}
}
