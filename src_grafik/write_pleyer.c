/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pleyer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 20:20:17 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/23 20:20:18 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_filler.h"

void	figura(t_grafik *grafik, int i, int j)
{
	int		x;
	int		len_y;
	int		y;

	i = (i + 1) * grafik->len;
	j = (j + 1) * grafik->len;
	x = i + grafik->len;
	len_y = j + grafik->len;
	while (++i < x)
	{
		y = j;
		while (++y < len_y)
			mlx_pixel_put(grafik->mlx, grafik->win, i, y, grafik->color);
	}
}

void	write_map(t_pleyer *pleyer, t_grafik *grafik)
{
	int i;
	int j;

	i = -1;
	if (!pleyer)
		return ;
	while (++i <= pleyer->len)
	{
		j = -1;
		while (++j < pleyer->h * grafik->len)
			mlx_pixel_put(grafik->mlx, grafik->win,
				(i + 1) * grafik->len, j + grafik->len, 0xFFFFFF);
	}
	i = -1;
	while (++i <= pleyer->h)
	{
		j = -1;
		while (++j < pleyer->len * grafik->len)
			mlx_pixel_put(grafik->mlx, grafik->win,
				j + grafik->len, (i + 1) * grafik->len, 0xFFFFFF);
	}
}

void	get_color_fig(int i, int j, t_grafik *grafik, t_pleyer *pleyer)
{
	while (++j < pleyer->len)
	{
		if (pleyer->map[i][j] == '.')
			continue;
		else if (pleyer->map[i][j] == 'X')
		{
			grafik->color = 0xFF0000;
			figura(grafik, j, i);
		}
		else if (pleyer->map[i][j] == 'x')
		{
			grafik->color = 0x0F00FF;
			figura(grafik, j, i);
		}
		else if (pleyer->map[i][j] == 'O')
		{
			grafik->color = 0x00FF00;
			figura(grafik, j, i);
		}
		if (pleyer->map[i][j] == 'o')
		{
			grafik->color = 0xF0FF00;
			figura(grafik, j, i);
		}
	}
}

void	write_pleyer(t_pleyer *pleyer, t_grafik *grafik)
{
	int i;
	int j;

	i = -1;
	if (!pleyer || !pleyer->map)
		return ;
	write_map(pleyer, grafik);
	while (++i < pleyer->h)
	{
		j = -1;
		get_color_fig(i, j, grafik, pleyer);
	}
	mlx_string_put(grafik->mlx, grafik->win, 1350, 100, 0x00FF00, pleyer->p1);
	mlx_string_put(grafik->mlx, grafik->win, 1350, 650, 0xFF0000, pleyer->p2);
}
