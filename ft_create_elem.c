/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:53:52 by videsvau          #+#    #+#             */
/*   Updated: 2016/11/24 17:02:39 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_create_elem(char content)
{
	t_list *chain;

	if (!(chain = (t_list*)malloc(sizeof(t_list))))
		return (0);
	chain->data = content;
	chain->next = NULL;
	return (chain);
}
