/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeconsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 02:41:13 by jeconsta          #+#    #+#             */
/*   Updated: 2016/12/19 19:14:20 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_map(char **map)
{
	int		x;
	int		y;
	int		rep;

	y = 0;
	x = 0;
	while (map[x])
		x++;
	rep = x;
	x = 0;
	while (x < (rep))
	{
		while (map[x][y])
		{
			ft_putchar(map[x][y]);
			y++;
		}
		ft_putchar('\n');
		y = 0;
		x++;
	}
}

int		ft_sqrt(t_lst *tetrim)
{
	int i;

	i = 2;
	while (i * i < (ft_dlistcount(tetrim) * 4))
		i++;
	return (i);
}

void	remove_tetri(char **map, char letter)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == letter)
				map[x][y] = '.';
			y++;
		}
		x++;
	}
}

void	ft_reset_map(char **map)
{
	int		x;

	x = 0;
	while (map[x])
		free(map[x++]);
}

char	**ft_map(int dim)
{
	char	**map;
	int		index;
	int		c;

	index = 0;
	c = 0;
	if (!(map = malloc(sizeof(char*) * (dim + 2))))
		return (NULL);
	while (index < (dim + 1))
	{
		if (!(map[index] = malloc(sizeof(char) * (dim + 1))))
			return (NULL);
		index++;
	}
	map[index + 1] = NULL;
	index = 0;
	while (index < dim + 1)
	{
		while (c < dim)
			map[index][c++] = '.';
		map[index][c] = '\0';
		c = 0;
		index++;
	}
	return (map);
}
