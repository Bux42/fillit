/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:01:43 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/20 18:12:41 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_list_push_back(t_list **alst, char content)
{
	t_list *first;
	t_list *after;

	first = ft_create_elem(content);
	if (!*alst)
		*alst = first;
	else
	{
		after = *alst;
		while (after->next)
			after = after->next;
		after->next = first;
	}
}

void	ft_lstdel(t_list **alst)
{
	t_list *list;

	list = *alst;
	while (list)
	{
		free(list);
		list = list->next;
	}
	*alst = NULL;
}

void	ft_dlistdel(t_lst *tetrim)
{
	while (tetrim)
	{
		ft_reset_map(tetrim->tetri);
		free(tetrim);
		tetrim = tetrim->next;
	}
	tetrim = NULL;
}
