/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:13:40 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/19 15:37:36 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_lstcount(t_list **alst)
{
	int		i;
	t_list	*chain;

	i = 1;
	chain = *alst;
	if (!chain)
		return (0);
	while (chain->next)
	{
		i++;
		chain = chain->next;
	}
	return (i);
}
