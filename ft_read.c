/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:59:45 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/19 15:59:12 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_add_letter(t_list **alst, char data)
{
	t_list	*first;
	t_list	*after;

	first = ft_create_elem(data);
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

int		ft_read(char *str)
{
	int		fd;
	char	c;
	t_list	*chain;
	char	t[0];

	chain = NULL;
	c = 'A';
	fd = open(str, O_RDONLY);
	while (read(fd, t, 1))
	{
		ft_add_letter(&chain, t[0]);
		c++;
	}
	if (ft_ls_error(&chain) > 0)
		ft_putstr("error\n");
	return (1);
}
