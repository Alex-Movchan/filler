/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manheten_distanc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 20:11:29 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/23 20:11:31 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_abs_int(int x, int y)
{
	return ((x - y) > 0 ? x - y : (x - y) * -1);
}

static int		**distanc(int **map, int i, int j, t_pleyer *pleyer)
{
	int		k;
	int		l;

	k = -1;
	while (++k < pleyer->h)
	{
		l = -1;
		while (++l < pleyer->len)
		{
			if (map[k][l] == -1)
				continue;
			if (map[k][l] > ft_abs_int(i, k) + ft_abs_int(l, j))
				map[k][l] = ft_abs_int(k, i) + ft_abs_int(l, j);
		}
	}
	return (map);
}

static int		**write_distanc(t_pleyer *pleyer, int **map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < pleyer->h)
	{
		j = -1;
		while (++j < pleyer->len)
			if (map[i][j] == 0)
			{
				map = distanc(map, i, j, pleyer);
			}
	}
	return (map);
}

int				**manheten(int **map, char **av, t_pleyer *pleyer)
{
	int		i;
	int		j;

	i = -1;
	while (++i < pleyer->h)
	{
		j = -1;
		while (++j < pleyer->len)
		{
			if (av[i][j] == pleyer->letar)
				map[i][j] = -1;
			else if (av[i][j] == pleyer->letar_fait)
				map[i][j] = 0;
			else
				map[i][j] = 1000000;
		}
	}
	i = -1;
	return (write_distanc(pleyer, map));
}
