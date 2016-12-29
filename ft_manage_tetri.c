/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeconsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 03:35:36 by jeconsta          #+#    #+#             */
/*   Updated: 2016/12/19 19:06:56 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	newline(int ok, int *y, int *x, int *w)
{
	*w += 1;
	if (ok)
	{
		*y -= 4;
		*x += 1;
	}
}

int		check(char **map, char **tetri, int x, int y)
{
	int		ok;
	int		w;
	int		z;

	w = 0;
	ok = 0;
	while (ok < 4)
	{
		z = 0;
		while (tetri[w][z] != '\n')
		{
			if (tetri[w][z] == '#' && map[x][y] != '.')
				return (0);
			if (tetri[w][z] == '#')
				ok++;
			z++;
			if (ok)
				y++;
		}
		if (map[x + 1] == NULL)
			return (0);
		newline(ok, &y, &x, &w);
	}
	return (1);
}

void	filltetri(char **map, t_lst *tetrim, int x, int y)
{
	int		ok;
	int		z;
	int		w;

	z = 0;
	w = 0;
	ok = 0;
	while (ok < 4)
	{
		while (tetrim->tetri[w][z] != '\n')
		{
			if (tetrim->tetri[w][z] == '#')
			{
				map[x][y] = tetrim->letter;
				ok++;
			}
			z++;
			if (ok)
				y++;
		}
		z = 0;
		newline(ok, &y, &x, &w);
	}
}

int		ft_checkpos(t_lst *tet, char **map, int x, int y)
{
	while (map[x])
	{
		if (map[x][y] == '.')
		{
			if (check(map, tet->tetri, x, y))
			{
				filltetri(map, tet, x, y);
				return (1);
			}
		}
		y += 1;
		if (map[x][y] == '\0')
		{
			y = 0;
			x += 1;
		}
	}
	x = 0;
	y = 0;
	return (0);
}
