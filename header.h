/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:34:29 by videsvau          #+#    #+#             */
/*   Updated: 2016/12/29 13:16:19 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_list
{
	char		data;
	void		*next;
}				t_list;

typedef	struct	s_lst
{
	char		**tetri;
	void		*next;
	char		letter;
}				t_lst;

void			ft_putchar(char c);
void			ft_putnbr(int i);
void			ft_putstr(char const *str);
void			ft_list_push_back(t_list **ast, char content);
void			d_list_push_back(t_lst **alst, char letter, char **content);
void			ft_reset_map(char **map);
void			filltetri(char **map, t_lst *tetri, int x, int y);
void			display_map(char **map);
void			remove_tetri(char **map, char letter);
void			ft_lstdel(t_list **alst);
void			ft_dlistdel(t_lst *tetrim);
char			*ft_strdup(char const *s1);
char			**ft_map(int dim);
int				ft_read(char *str);
int				ft_open(char *str);
int				ft_columns(t_list **chain);
int				ft_lstcount(t_list **alst);
int				ft_dlistcount(t_lst *tetrim);
int				ft_ls_error(t_list **alst);
int				newlines(t_list **alst);
int				ft_ls_to_array(t_list **alst, t_lst *tetrim);
int				ft_rec(char **map, t_lst *tetrim);
int				ft_count_con(t_lst *tet);
int				check(char **map, char **tetri, int x, int y);
int				ft_checkpos(t_lst *tet, char **map, int x, int y);
int				ft_sqrt(t_lst *tetrim);
int				ft_dlistcount(t_lst *tetrim);
int				ft_count_dots(t_list **alst);
t_list			*ft_create_elem(char content);
t_lst			*t_lst_create_elem(char **content, char letter);

#endif
