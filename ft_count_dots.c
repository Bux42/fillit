/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:06:37 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/29 17:28:00 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_count_dots(t_list **alst)
{
	int dot;
	int tetri;

	dot = 0;
	tetri = 1;
	while (*alst)
	{
		if (tetri % 21 == 0)
		{
			if (dot != 12)
				return (1);
			dot = 0;
		}
		if ((*alst)->data == '.')
			dot++;
		*alst = (*alst)->next;
		tetri++;
	}
	if (tetri % 21 == 0)
	{
		if (dot != 12)
			return (1);
	}
	return (0);
}
