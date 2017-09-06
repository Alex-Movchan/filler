/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:55:35 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/23 21:04:25 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_pleyer	*new_pleyer(t_pleyer *pleyer)
{
	pleyer = (t_pleyer*)malloc(sizeof(t_pleyer));
	pleyer->map = NULL;
	pleyer->pice = NULL;
	pleyer->len = 0;
	pleyer->h = 0;
	pleyer->h_pic = 0;
	pleyer->len_pic = 0;
	return (pleyer);
}

int				main(void)
{
	read_params(new_pleyer(NULL));
	return (0);
}
