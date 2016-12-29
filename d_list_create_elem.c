/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:53:52 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/20 17:53:50 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_lst	*d_list_create_elem(char **content, char letter)
{
	t_lst *chain;

	if (!(chain = (t_lst*)malloc(sizeof(t_lst))))
		return (0);
	chain->tetri = content;
	chain->letter = letter;
	chain->next = NULL;
	return (chain);
}

void	d_list_push_back(t_lst **alst, char letter, char **content)
{
	t_lst *first;
	t_lst *after;

	first = d_list_create_elem(content, letter);
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
