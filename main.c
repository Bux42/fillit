/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:28:29 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/29 17:22:27 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "usage: ./fillit source file\n", 29);
		return (0);
	}
	if (ft_open(argv[1]) == -1)
	{
		write(1, "File doesn't exist/no permissions\n", 34);
		return (0);
	}
	else
		ft_read(argv[1]);
	return (0);
}
