/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:59:50 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/19 01:40:05 by jeconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_columns(t_list **chain)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *chain;
	while (tmp)
	{
		if (tmp->data == '\n')
			i++;
		tmp = tmp->next;
	}
	return (i);
}
