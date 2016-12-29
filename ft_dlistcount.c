/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:35:47 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/19 15:37:27 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_dlistcount(t_lst *tetrim)
{
	int i;

	i = 1;
	while (tetrim->next)
	{
		i++;
		tetrim = tetrim->next;
	}
	return (i);
}
