/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pieca.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:58:39 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/13 17:58:41 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_pic		*xy_piec2(t_pic *begin, int i, int j)
{
	t_pic *pic;

	pic = begin;
	while (pic && pic->next)
		pic = pic->next;
	if (!pic)
	{
		pic = (t_pic*)malloc(sizeof(t_pic));
		pic->x = i;
		pic->y = j;
		pic->next = NULL;
		begin = pic;
	}
	else
	{
		pic->next = (t_pic *)malloc(sizeof(t_pic));
		pic = pic->next;
		pic->x = i;
		pic->y = j;
		pic->next = NULL;
	}
	return (begin);
}

static t_pic		*xy_piec(t_pleyer *pleyer)
{
	int		i;
	int		j;
	t_pic	*begin;

	i = -1;
	begin = NULL;
	while (++i < pleyer->h_pic)
	{
		j = -1;
		while (++j < pleyer->len_pic)
		{
			if (pleyer->pice[i][j] == '*')
				begin = xy_piec2(begin, i, j);
		}
	}
	return (begin);
}

static int			intersection_letar(int i, int j, t_pleyer *pleyer)
{
	t_pic	*pic;
	int		count;
	int		len;

	count = 0;
	len = 0;
	pic = xy_piec(pleyer);
	while (pic)
	{
		if (i + pic->x < pleyer->h && j + pic->y < pleyer->len &&
				(pleyer->map[i + pic->x][j + pic->y] == 0))
			return (0);
		else if (i + pic->x < pleyer->h && j + pic->y < pleyer->len &&
				pleyer->map[i + pic->x][j + pic->y] == -1)
			count++;
		else if (i + pic->x < pleyer->h && j + pic->y < pleyer->len)
			len += pleyer->map[i + pic->x][j + pic->y];
		pic = pic->next;
		if (count > 1)
			return (0);
	}
	if (count != 1)
		return (0);
	else
		return (len);
}

static int			*search_for_place(t_pleyer **pleyer)
{
	int i[2];
	int *j;
	int nbr;
	int nb;

	nbr = 1000000;
	i[0] = -1;
	j = (int *)malloc(sizeof(int) * 2);
	while ((++i[0] + (*pleyer)->h_pic) <= (*pleyer)->h)
	{
		i[1] = -1;
		while ((++i[1] + (*pleyer)->len_pic) <= (*pleyer)->len)
		{
			if ((nb = intersection_letar(i[0], i[1], *pleyer)) < nbr && nb > 0)
			{
				nbr = nb;
				j[0] = i[0];
				j[1] = i[1];
			}
		}
	}
	return (j);
}

void				ft_put_pieca(t_pleyer *pleyer)
{
	int *tab;

	if ((tab = search_for_place(&pleyer)))
		ft_printf("%d %d\n", tab[0], tab[1]);
	free(tab);
}
