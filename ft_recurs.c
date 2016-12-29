/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeconsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:45:34 by jeconsta          #+#    #+#             */
/*   Updated: 2016/12/20 16:50:01 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_rec(char **map, t_lst *tetrim)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '.' && ft_checkpos(tetrim, map, x, y))
			{
				if (!tetrim->next)
					return (1);
				if (ft_rec(map, tetrim->next))
					return (1);
				else
					remove_tetri(map, tetrim->letter);
			}
			y++;
		}
		x++;
	}
	return (0);
}
