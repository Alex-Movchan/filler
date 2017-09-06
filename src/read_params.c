/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 20:03:17 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/23 20:03:20 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		**new_int_tab(int **tab, int size, int len)
{
	int		i;

	i = -1;
	tab = (int**)malloc(sizeof(int*) * size);
	while (++i < size)
		tab[i] = (int*)malloc(sizeof(int) * (len));
	return (tab);
}

static int		**ft_newmap(char *str, t_pleyer **pleyer)
{
	char	*lin;
	int		i;
	char	**av;

	i = -1;
	(*pleyer)->h = ft_atoi(str + 8);
	(*pleyer)->len = ft_atoi(str + ((*pleyer)->h == 100 ? 12 : 11));
	av = (char**)malloc(sizeof(char*) * ((*pleyer)->h + 1));
	get_next_line(0, &lin);
	while (++i < (*pleyer)->h)
	{
		get_next_line(0, &lin);
		av[i] = ft_strdup(lin + 4);
	}
	return (manheten(new_int_tab(NULL,
						(*pleyer)->h, (*pleyer)->len), av, *pleyer));
}

static void		ft_new_piece(char *lin, t_pleyer **pleyer)
{
	int		i;
	char	**av;

	i = -1;
	if ((*pleyer)->pice)
		(*pleyer)->pice = NULL;
	av = ft_strsplit(lin, ' ');
	(*pleyer)->h_pic = ft_atoi(av[1]);
	(*pleyer)->len_pic = ft_atoi(av[2]);
	(*pleyer)->pice = (char**)malloc(sizeof(char*) * ((*pleyer)->h_pic + 1));
	while (++i < (*pleyer)->h_pic)
	{
		get_next_line(0, &lin);
		(*pleyer)->pice[i] = ft_strdup(lin);
	}
	(*pleyer)->pice[++i] = NULL;
}

static t_pleyer	*ft_dell_pleyer(t_pleyer *pleyer)
{
	pleyer->pice = NULL;
	pleyer->h_pic = 0;
	pleyer->len_pic = 0;
	pleyer->map = NULL;
	pleyer->len = 0;
	pleyer->h = 0;
	return (pleyer);
}

void			read_params(t_pleyer *pleyer)
{
	char	*lin;

	lin = 0;
	while (get_next_line(0, &lin) > 0)
	{
		if (lin[10] == '2')
		{
			pleyer->letar = 'X';
			pleyer->letar_fait = 'O';
		}
		else if (lin[10] == '1')
		{
			pleyer->letar = 'O';
			pleyer->letar_fait = 'X';
		}
		else if (!ft_strncmp(lin, "Plateau", 7))
		{
			pleyer->map = ft_newmap(lin, &pleyer);
			get_next_line(0, &lin);
			ft_new_piece(lin, &pleyer);
			ft_put_pieca(pleyer);
			pleyer = ft_dell_pleyer(pleyer);
		}
	}
}
