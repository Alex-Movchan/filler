/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 20:19:34 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/23 20:19:35 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_filler.h"

static void	ft_pleers_name(char *str, t_pleyer *pleyer)
{
	char	*name;
	char	*nbr_nema;

	name = str;
	while (*name != 'p')
		name++;
	nbr_nema = name;
	while (*name != '/')
	{
		if (*name == '.' && name++ && *name == '/')
			name++;
		else
			name++;
	}
	name++;
	if (!ft_strncmp(nbr_nema, "p1", 2))
		pleyer->p1 = ft_strndup(name, ft_strlen(name) - 1);
	else
		pleyer->p2 = ft_strndup(name, ft_strlen(name) - 1);
}

static char	**ft_newmap(char *str, char **map, t_pleyer **pleyer)
{
	char	*src;
	int		i;

	i = -1;
	(*pleyer)->h = ft_atoi(str + 8);
	(*pleyer)->len = ft_atoi(str + ((*pleyer)->h == 100 ? 12 : 11));
	map = (char**)malloc(sizeof(char*) * ((*pleyer)->h + 1));
	get_next_line(0, &src);
	while (++i < (*pleyer)->h)
	{
		get_next_line(0, &src);
		map[i] = ft_strdup(src + 4);
	}
	(*pleyer)->grafik->len = ft_cast_len((*pleyer)->h);
	return (map);
}

static void	ft_win_loss(int p1, int p2, t_pleyer *pleyer)
{
	if (p1 > p2)
	{
		mlx_string_put(pleyer->grafik->mlx, pleyer->grafik->win,
				1500, 150, 0x00FF00, ft_itoa(p1));
		mlx_put_image_to_window(pleyer->grafik->mlx, pleyer->grafik->win,
				pleyer->grafik->imegewin, 1350, 200);
		mlx_string_put(pleyer->grafik->mlx, pleyer->grafik->win,
				1400, 700, 0xFF0000, ft_itoa(p2));
		mlx_put_image_to_window(pleyer->grafik->mlx, pleyer->grafik->win,
				pleyer->grafik->imagelose, 1350, 750);
	}
	else if (p1 < p2)
	{
		mlx_string_put(pleyer->grafik->mlx, pleyer->grafik->win,
				1400, 150, 0x00FF00, ft_itoa(p1));
		mlx_put_image_to_window(pleyer->grafik->mlx, pleyer->grafik->win,
				pleyer->grafik->imagelose, 1350, 200);
		mlx_string_put(pleyer->grafik->mlx, pleyer->grafik->win,
				1400, 700, 0xFF0000, ft_itoa(p2));
		mlx_put_image_to_window(pleyer->grafik->mlx, pleyer->grafik->win,
				pleyer->grafik->imegewin, 1350, 750);
	}
}

t_pleyer	*finish_batl(char *lin, t_pleyer *pleyer)
{
	char	*src;
	int		nb;
	int		p1;
	int		p2;

	if (ft_strncmp("== ", lin, 3))
		return (pleyer);
	src = lin;
	nb = src[3] == 'O' ? 1 : 2;
	if (nb == 1)
		p1 = ft_atoi(src + 10);
	else
		p2 = ft_atoi(src + 10);
	get_next_line(0, &src);
	nb = src[3] == 'O' ? 1 : 2;
	if (nb == 1)
		p1 = ft_atoi(src + 10);
	else
		p2 = ft_atoi(src + 10);
	ft_win_loss(p1, p2, pleyer);
	return (pleyer);
}

t_pleyer	*read_params(char *lin, t_pleyer *pleyer)
{
	while (get_next_line(0, &lin) > 0)
	{
		if (!ft_strncmp(lin, "== ", 3))
			return (finish_batl(lin, pleyer));
		else if (!ft_strncmp(lin, "$$$ exec p1", 11) ||
				!ft_strncmp(lin, "$$$ exec p2", 11))
			ft_pleers_name(lin, pleyer);
		else if (!ft_strncmp(lin, "Plateau", 7))
			pleyer->map = ft_newmap(lin, NULL, &pleyer);
		else if (!ft_strncmp(lin, "<got", 4))
			return (pleyer);
	}
	return (NULL);
}
