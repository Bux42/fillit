/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:22:30 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/29 13:16:21 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_newline(t_list **alst)
{
	int		i;
	int		k;

	k = 0;
	i = 1;
	while (*alst)
	{
		if (i % 21 == 0)
		{
			if ((*alst)->data == '\n')
				k++;
			else
				return (1);
		}
		if ((i - k) % 5 == 0)
		{
			if ((*alst)->data != '\n')
				return (1);
		}
		*alst = (*alst)->next;
		i++;
	}
	if (i % 21 != 0)
		return (1);
	return (0);
}

int		ft_countchar(t_list **alst)
{
	int		sharp;
	int		tetri;

	sharp = 0;
	tetri = 1;
	while (*alst)
	{
		if (tetri % 21 == 0)
		{
			if (sharp != 4)
				return (1);
			sharp = 0;
		}
		if ((*alst)->data == '#')
			sharp++;
		*alst = (*alst)->next;
		tetri++;
	}
	if (tetri % 21 == 0)
	{
		if (sharp != 4)
			return (1);
	}
	return (0);
}

int		count(char **tet, int x, int y)
{
	int		con;

	con = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			if (tet[x][y] == '#')
			{
				if (y > 0 && tet[x][y - 1] == '#')
					con++;
				if (y < 3 && tet[x][y + 1] == '#')
					con++;
				if (x > 0 && tet[x - 1][y] == '#')
					con++;
				if (x < 3 && tet[x + 1][y] == '#')
					con++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (con);
}

int		ft_count_con(t_lst *tet)
{
	int		con;
	int		x;
	int		y;

	while (tet)
	{
		x = 0;
		y = 0;
		con = count(tet->tetri, x, y);
		if (con != 6 && con != 8)
			return (1);
		tet = tet->next;
	}
	return (0);
}

int		ft_ls_error(t_list **alst)
{
	int		error;
	t_list	*tmp;
	t_lst	*tetrim;

	tetrim = NULL;
	tmp = *alst;
	error = 0;
	error += ft_newline(&tmp);
	tmp = *alst;
	error += ft_countchar(&tmp);
	tmp = *alst;
	error += ft_count_dots(&tmp);
	tmp = *alst;
	if (error > 0)
		return (1);
	if (ft_ls_to_array(&tmp, tetrim) == 1)
		return (1);
	ft_dlistdel(tetrim);
	return (error);
}
