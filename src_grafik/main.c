/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 20:19:48 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/23 20:19:49 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_filler.h"

static t_pleyer	*ft_pleyer(t_pleyer *pleyer)
{
	pleyer = (t_pleyer*)malloc(sizeof(t_pleyer));
	pleyer->p1 = NULL;
	pleyer->p2 = NULL;
	pleyer->map = NULL;
	pleyer->grafik = NULL;
	return (pleyer);
}

int				ft_cast_len(int nb)
{
	if (nb == 15)
		return (70);
	else if (nb == 24)
		return (30);
	else
		return (13);
}

int				my_key_funct(int key, t_pleyer *pleyer)
{
	if (key == 53)
		exit(0);
	if (key == 124)
	{
		pleyer = read_params(NULL, pleyer);
		if (pleyer)
		{
			write_pleyer(pleyer, pleyer->grafik);
			pleyer->map = NULL;
		}
		return (1);
	}
	else
		return (0);
}

char			*ft_strndup(char *str, size_t len)
{
	char	*src;

	if (!(src = ft_strnew(len)))
		return (NULL);
	src = ft_strncpy(src, str, len);
	return (src);
}

int				main(void)
{
	t_pleyer	*pleyer;
	t_grafik	*grafik;

	pleyer = ft_pleyer(NULL);
	grafik = (t_grafik*)malloc(sizeof(t_grafik));
	grafik->mlx = mlx_init();
	pleyer->grafik = grafik;
	grafik->imegewin = mlx_xpm_file_to_image(grafik->mlx,
		"win.xpm", &grafik->width, &grafik->height);
	grafik->imagelose = mlx_xpm_file_to_image(grafik->mlx,
		"lose.xpm", &grafik->width2, &grafik->height2);
	grafik->win = mlx_new_window(grafik->mlx, 2000, 1350, "Filler");
	mlx_hook(grafik->win, 2, 3, my_key_funct, pleyer);
	mlx_loop(grafik->mlx);
	return (0);
}
