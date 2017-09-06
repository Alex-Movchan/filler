/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:55:24 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/23 21:03:24 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_pic
{
	int				x;
	int				y;
	struct s_pic	*next;
}					t_pic;

typedef struct		s_pleyer
{
	char			letar;
	char			letar_fait;
	char			**pice;
	int				len_pic;
	int				h_pic;
	int				**map;
	int				len;
	int				h;
}					t_pleyer;

void				read_params(t_pleyer *pleyer);
void				ft_put_pieca(t_pleyer *pleyer);
void				ft_dell_arrey(char ***arry);
int					**manheten(int **map, char **av, t_pleyer *pleyer);
int					ft_abs_int(int x, int y);

#endif
