/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_filler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:54:14 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/23 21:03:38 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_FILLER_H
# define VISUAL_FILLER_H

# include "../libft/libft.h"
# include "mlx.h"

typedef struct	s_grafik
{
	void		*mlx;
	void		*win;
	int			color;
	int			len;
	void		*imegewin;
	void		*imagelose;
	int			width;
	int			width2;
	int			height;
	int			height2;
}				t_grafik;

typedef struct	s_pleyer
{
	char		*p1;
	char		*p2;
	char		**map;
	int			len;
	int			h;
	t_grafik	*grafik;
}				t_pleyer;

t_pleyer		*read_params(char *lin, t_pleyer *pleyer);
void			write_pleyer(t_pleyer *pleyer, t_grafik *grafik);
char			*ft_strndup(char *str, size_t len);
int				ft_cast_len(int nb);

#endif
