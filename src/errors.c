/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:43:58 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/09 16:44:00 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void		error_parse(void)
{
	ft_putstr("file parsing error");
	exit(0);
}

void		error_open(void)
{
	ft_putstr("invalid file");
	exit(0);
}
