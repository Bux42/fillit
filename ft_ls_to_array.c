/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:12:19 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/20 18:17:24 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char	**ft_malloc_tetri(void)
{
	char	**tetri;
	int		j;

	j = 0;
	if (!(tetri = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	while (j < 4)
	{
		if (!(tetri[j] = (char*)malloc(sizeof(char) * 6)))
			return (NULL);
		tetri[j][5] = '\0';
		j++;
	}
	return (tetri);
}

char	**ft_tetrim(t_list **alst, int i)
{
	char	**tetri;
	int		x[3];

	x[1] = 0;
	x[2] = 0;
	x[0] = 0;
	tetri = ft_malloc_tetri();
	while (x[0] < (i * 21))
	{
		(*alst) = (*alst)->next;
		x[0]++;
	}
	x[0] = 0;
	while (x[0] < 20)
	{
		tetri[x[1]][x[2]] = (*alst)->data;
		(*alst) = (*alst)->next;
		x[0]++;
		x[2]++;
		if (x[2] == 5)
			x[2] = 0;
		if (x[2] == 0)
			x[1]++;
	}
	return (tetri);
}

void	rmvlastline(char **map, int i)
{
	free(map[i]);
	map[i] = NULL;
	display_map(map);
}

int		ft_ls_to_array(t_list **alst, t_lst *tetrim)
{
	t_list	*tmp;
	int		i;
	char	**map;

	tmp = *alst;
	i = -1;
	tmp = *alst;
	while (i++ + 1 <= (ft_lstcount(&tmp)) + 1 / 21)
	{
		tmp = *alst;
		d_list_push_back(&tetrim, i + 65, ft_tetrim(&tmp, i));
	}
	if (ft_count_con(tetrim) == 1)
		return (1);
	i = ft_sqrt(tetrim);
	map = ft_map(i);
	while (!ft_rec(map, tetrim))
	{
		i++;
		ft_reset_map(map);
		free(map);
		map = ft_map(i);
	}
	rmvlastline(map, i);
	return (0);
}
